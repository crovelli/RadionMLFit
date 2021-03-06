MLOptions GetDefaultOptions() {
  MLOptions opts;
  // Fit configuration
  opts.addBoolOption("dataFit",         "Fit all species",                kFALSE);
  opts.addBoolOption("sgnOnlyFit",      "Fit signal only",                kTRUE);
  opts.addBoolOption("bkgOnlyFit",      "Fit bkg species only",           kFALSE);
  opts.addBoolOption("weightedDataset", "use event weight instead of 1",  kFALSE);

  return opts;
}

//===================================
// make the RooDataSet from ROOT tree
//=================================== 
RooDataSet *getDataSet(const char *rootfile, const char *treename) {    
  
  cout << "roofitting file " << rootfile << endl;
  
  // fit variables
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]",         100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",                10., 300.);
  RooRealVar* mggjj        = new RooRealVar("mggjj",        "m_{#gamma #gammajet jet} [GeV]",   10., 1500.); //chiara!
  
  // needed bools
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory", 0.9,2.1);

  // weights
  RooRealVar* weight = new RooRealVar("weight", "weight",0,10.);

  RooArgSet setall(*massggnewvtx,*mjj,*mggjj,*btagCategory,*weight);            

  TFile *file = TFile::Open(rootfile);
  TTree *tree = (TTree*)file->Get(treename);

  RooDataSet *data = new RooDataSet("myTrees","dataset",tree,setall,0,weight->GetName());     // chiara!
  // RooDataSet *data = new RooDataSet("myTrees","dataset",tree,setall,0);

  data->Print();

  return data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Fit a sample of gg events - data or mc
void FitGG_perSignalRegion() {   
  
  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]",  100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",         10., 300.);
  RooRealVar* mggjj        = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]",   10., 1500.); //chiara!
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory",             -0.9,2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(mggjj);
  theFit.AddFlatFileColumn(btagCategory);

  // define a fit model
  theFit.addModel("myFit", "HtoGG");
  
  // define species
  theFit.addSpecies("myFit", "sig", "Signal Component");
  theFit.addSpecies("myFit", "bkg", "Bkg   Component");
  
  // mgg PDF - signal
  // theFit.addPdfWName("myFit", "sig" , "massggnewvtx",  "Cruijff",  "sig_Mass");           
  theFit.addPdfWName("myFit", "sig" , "massggnewvtx",  "Totti",  "sig_Mass");          

  // mLL PDF - background
  theFit.addPdfWName("myFit", "bkg" , "massggnewvtx",  "Expo", "bkg_Mass");      

  // Load the data
  char datasetnameB[200];
  sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_presel/Radion_Data2012_default_CSV.root");  

  char datasetnameS[200];
  sprintf(datasetnameS, "../HHggbb/finalizedTrees_Radion_presel/Radion_Radion_M-300_madgraph_default_CSV.root");

  char treename[100];
  sprintf(treename,"myTrees");   

  RooDataSet *data;
  if(opts.getBoolVal("sgnOnlyFit")) data = getDataSet(datasetnameS,  treename);
  if(opts.getBoolVal("bkgOnlyFit")) data = getDataSet(datasetnameB,  treename);
  if(opts.getBoolVal("dataFit"))    data = getDataSet(datasetnameB,  treename);

  data = (RooDataSet*)data->reduce("massggnewvtx>=100 && massggnewvtx<=180 && mjj>98.5 && mjj<151.5 && mggjj>270 && mggjj<330");   // chiara

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");
  
  // Initialize the fit
  char fitconfig[200];
  if(opts.getBoolVal("sgnOnlyFit"))    sprintf(fitconfig,"fitconfig/fitSignal.config");    
  if(opts.getBoolVal("bkgOnlyFit"))    sprintf(fitconfig,"fitconfig/fitBackground.config");    
  if(opts.getBoolVal("dataFit"))       sprintf(fitconfig,"fitconfig/fitData.config");    
  theFit.initialize(fitconfig);
  
  // Print Fit configuration 
  myPdf->getParameters(data)->selectByAttrib("Constant",kTRUE)->Print("V");  
  myPdf->getParameters(data)->selectByAttrib("Constant",kFALSE)->Print("V");

  RooFitResult *fitres =  myPdf->fitTo(*data,
                                       RooFit::ConditionalObservables(theFit.getNoNormVars("myFit")),
                                       RooFit::FitOptions("MHTER"),
                                       RooFit::NumCPU(4));
  fitres->Print("V");

  // write the config file corresponding to the fit minimum
  char configfilename[200];
  if(opts.getBoolVal("sgnOnlyFit"))    theFit.writeConfigFile("fitres/fitSignal.config");  
  if(opts.getBoolVal("bkgOnlyFit"))    theFit.writeConfigFile("fitres/fitBackground.config");  
  if(opts.getBoolVal("dataFit"))       theFit.writeConfigFile("fitres/fitData.config");    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlotGG(int nbins=19) {    

  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        10., 300.);
  RooRealVar* mggjj        = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]",  10., 1500.); //chiara!
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory",            -0.9,2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(mggjj);
  theFit.AddFlatFileColumn(btagCategory);

  // define a fit model
  theFit.addModel("myFit", "HtoGG");
  
  // define species
  theFit.addSpecies("myFit", "sig", "Signal Component");
  theFit.addSpecies("myFit", "bkg", "Bkg   Component");
  
  // mgg PDF - signal
  // theFit.addPdfWName("myFit", "sig" , "massggnewvtx",  "Cruijff",  "sig_Mass");       
  theFit.addPdfWName("myFit", "sig" , "massggnewvtx",  "Totti",  "sig_Mass");
                                                                                
  // mLL PDF - background
  // theFit.addPdfWName("myFit", "bkg" , "massggnewvtx",  "Bernstein3", "bkg_Mass");     
  theFit.addPdfWName("myFit", "bkg" , "massggnewvtx",  "Expo", "bkg_Mass");     

  // Load the data
  char datasetnameB[200];
  sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_presel/Radion_Data2012_default_CSV.root");  

  char datasetnameS[200];
  sprintf(datasetnameS, "../HHggbb/finalizedTrees_Radion_presel/Radion_Radion_M-300_madgraph_default_CSV.root");

  char treename[100];
  sprintf(treename,"myTrees");  

  RooDataSet *data;
  if(opts.getBoolVal("sgnOnlyFit")) data = getDataSet(datasetnameS,  treename);
  if(opts.getBoolVal("bkgOnlyFit")) data = getDataSet(datasetnameB,  treename);
  if(opts.getBoolVal("dataFit"))    data = getDataSet(datasetnameB,  treename);
  data = (RooDataSet*)data->reduce("massggnewvtx>=100 && massggnewvtx<=180 && mjj>98.5 && mjj<151.5 && mggjj>270 && mggjj<330"); // chiara

  bool usePoissonError=true;
  // use event weights
  if(opts.getBoolVal("weightedDataset")) {
    usePoissonError=false;
  }

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // Initialize the fit...
  char configfilename[200];
  if(opts.getBoolVal("sgnOnlyFit"))    theFit.initialize("fitres/fitSignal.config");  
  if(opts.getBoolVal("bkgOnlyFit"))    theFit.initialize("fitres/fitBackground.config");  
  if(opts.getBoolVal("dataFit"))       theFit.initialize("fitres/fitData.config");    

  // Plots
  TCanvas *c = new TCanvas("c","fitResult");
  char rootfilename[200];
  if(opts.getBoolVal("sgnOnlyFit"))    sprintf(rootfilename,"fitres/mGGSignal.root");  
  if(opts.getBoolVal("bkgOnlyFit"))    sprintf(rootfilename,"fitres/mGGBackground.root");  
  if(opts.getBoolVal("dataFit"))       sprintf(rootfilename,"fitres/mGGData.root");    

  TFile *output = new TFile(rootfilename,"RECREATE");   

  //////////////////////////////
  RooRealVar* Var = theFit.RealObservable("massggnewvtx");  
  double min=Var->getMin();
  double max=Var->getMax();
  RooPlot *plot = Var->frame(min,max,nbins);
  
  // plot the data
  data->plotOn(plot, RooFit::DataError(RooAbsData::SumW2) );

  // plot the total likelihood
  RooAbsPdf *thePdf = theFit.getPdf("myFit");

  // plot background 
  thePdf->plotOn(plot, RooFit::LineColor(kBlack));

  plot->SetYTitle("Events");
  plot->Draw();
  char epsfilename[200];
  if(opts.getBoolVal("sgnOnlyFit")) c->SaveAs("fitres/mGGSignal.png");  
  if(opts.getBoolVal("bkgOnlyFit")) c->SaveAs("fitres/mGGBackground.png");  
  if(opts.getBoolVal("dataFit"))    c->SaveAs("fitres/mGGData.png");  
  plot->Write();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Make the plot for a given variable
RooPlot *MakePlot(TString VarName, MLFit* theFit, RooDataSet* theData, int nbins, bool poissonError=true)
{

  return plot;
}

