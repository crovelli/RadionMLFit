MLOptions GetDefaultOptions() {
  MLOptions opts;
  // Fit configuration
  opts.addBoolOption("dataFit",         "Fit all species",                kTRUE);
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
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj", "m_{jet jet} [GeV]", 0., 300.);
  
  // needed bools
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory", 0.9,2.1);

  // weights
  RooRealVar* weight = new RooRealVar("weight", "weight",0,10.);

  RooArgSet setall(*massggnewvtx,*mjj,*btagCategory,*weight);

  TFile *file = TFile::Open(rootfile);
  TTree *tree = (TTree*)file->Get(treename);

  // RooDataSet *data = new RooDataSet("T1","dataset",tree,setall,0,weight->GetName());     
  RooDataSet *data = new RooDataSet("myTrees","dataset",tree,setall,0);

  data->Print();

  return data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Fit a sample of gg events - data or mc
void FitGG() {   
  
  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",       0., 300.);
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory",           -0.9,2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(btagCategory);

  // to restrict to sidebands - not fully working....
  // massggnewvtx->setRange("R1",100.,120.) ;
  // massggnewvtx->setRange("R2",130.,180.) ; 

  // define a fit model
  theFit.addModel("myFit", "HtoGG");
  
  // define species
  theFit.addSpecies("myFit", "sig", "Signal Component");
  theFit.addSpecies("myFit", "bkg", "Bkg   Component");
  
  // mgg PDF - signal
  theFit.addPdfWName("myFit", "sig" , "massggnewvtx",  "Cruijff",  "sig_Mass");           
                                                                                
  // mLL PDF - background
  // theFit.addPdfWName("myFit", "bkg" , "massggnewvtx",  "Bernstein3", "bkg_Mass");   
  theFit.addPdfWName("myFit", "bkg" , "massggnewvtx",  "Expo", "bkg_Mass");        

  // Load the data
  char datasetnameB[200];
  sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_codiceCommittato/Radion_Data2012_default_CSV.root");  

  char treename[100];
  sprintf(treename,"myTrees");   

  RooDataSet *data;
  if(opts.getBoolVal("bkgOnlyFit")) data = getDataSet(datasetnameB,  treename);
  if(opts.getBoolVal("dataFit"))    data = getDataSet(datasetnameB,  treename);

  // data = (RooDataSet*)data->reduce("massggnewvtx>=100 && massggnewvtx<=180 && (massggnewvtx>=130 || massggnewvtx<=120) && mjj>0 && mjj<300");
  data = (RooDataSet*)data->reduce("massggnewvtx>=100 && massggnewvtx<=180 && mjj>0 && mjj<300");

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");
  
  // Initialize the fit
  char fitconfig[200];
  if(opts.getBoolVal("bkgOnlyFit"))    sprintf(fitconfig,"fitconfig/fitBackground.config");    
  if(opts.getBoolVal("dataFit"))       sprintf(fitconfig,"fitconfig/fitData.config");    
  theFit.initialize(fitconfig);
  
  // Print Fit configuration 
  myPdf->getParameters(data)->selectByAttrib("Constant",kTRUE)->Print("V");  
  myPdf->getParameters(data)->selectByAttrib("Constant",kFALSE)->Print("V");
  
  RooFitResult *fitres =  myPdf->fitTo(*data,
				       // RooFit::Range("R1,R2"),   
                                       RooFit::ConditionalObservables(theFit.getNoNormVars("myFit")),
                                       RooFit::FitOptions("MHTER"),
                                       RooFit::NumCPU(4));
  fitres->Print("V");
  
  // write the config file corresponding to the fit minimum
  char configfilename[200];
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
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",       0., 300.);
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory",           -0.9,2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(btagCategory);

  // to restrict to sidebands - not fully working
  // massggnewvtx->setRange("R1",100.,120.) ;
  // massggnewvtx->setRange("R2",130.,180.) ; 

  // define a fit model
  theFit.addModel("myFit", "HtoGG");
  
  // define species
  theFit.addSpecies("myFit", "sig", "Signal Component");
  theFit.addSpecies("myFit", "bkg", "Bkg   Component");
  
  // mgg PDF - signal
  theFit.addPdfWName("myFit", "sig" , "massggnewvtx",  "Cruijff",  "sig_Mass");     
                                                                               
  // mLL PDF - background
  // theFit.addPdfWName("myFit", "bkg" , "massggnewvtx",  "Bernstein3", "bkg_Mass");    
  theFit.addPdfWName("myFit", "bkg" , "massggnewvtx",  "Expo", "bkg_Mass");     

  // Load the data
  char datasetnameB[200];
  sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_codiceCommittato/Radion_Data2012_default_CSV.root");  

  char treename[100];
  if(opts.getBoolVal("dataFit")) sprintf(treename,"myTrees");  

  RooDataSet *data;
  if(opts.getBoolVal("bkgOnlyFit")) data = getDataSet(datasetnameB,  treename);
  if(opts.getBoolVal("dataFit"))    data = getDataSet(datasetnameB,  treename);
  // data = (RooDataSet*)data->reduce("massggnewvtx>=100 && massggnewvtx<=180 && (massggnewvtx>=130 || massggnewvtx<=120) && mjj>0 && mjj<300");
  data = (RooDataSet*)data->reduce("massggnewvtx>=100 && massggnewvtx<=180 && mjj>0 && mjj<300");

  bool usePoissonError=true;
  // use event weights
  if(opts.getBoolVal("weightedDataset")) {
    usePoissonError=false;
  }

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // Initialize the fit...
  char configfilename[200];
  if(opts.getBoolVal("bkgOnlyFit"))    theFit.initialize("fitres/fitBackground.config");  
  if(opts.getBoolVal("dataFit"))       theFit.initialize("fitres/fitData.config");    

  // Plots
  TCanvas *c = new TCanvas("c","fitResult");
  char rootfilename[200];
  if(opts.getBoolVal("bkgOnlyFit"))    sprintf(rootfilename,"fitres/mGGBackground.root");  
  if(opts.getBoolVal("dataFit"))       sprintf(rootfilename,"fitres/mGGData.root");    

  TFile *output = new TFile(rootfilename,"RECREATE");   

  RooPlot* MassPlot = MakePlot("massggnewvtx", &theFit, data, nbins, false);    

  MassPlot->SetYTitle("Events");
  MassPlot->Draw();
  char epsfilename[200];
  if(opts.getBoolVal("bkgOnlyFit")) c->SaveAs("fitres/mGGBackground.png");  
  if(opts.getBoolVal("dataFit"))    c->SaveAs("fitres/mGGData.png");  
  MassPlot->Write();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Make the plot for a given variable
RooPlot *MakePlot(TString VarName, MLFit* theFit, RooDataSet* theData, int nbins, bool poissonError=true)
{
  RooRealVar* Var = theFit->RealObservable(VarName);
  double min=Var->getMin();
  double max=Var->getMax();
  RooPlot *plot = Var->frame(min,max,nbins);
  
  // plot the data
  if(poissonError)       
    theData->plotOn(plot);
  else 
    theData->plotOn(plot, RooFit::DataError(RooAbsData::SumW2) );

  // plot the total likelihood
  RooAbsPdf *thePdf = theFit->getPdf("myFit");
  thePdf->plotOn(plot, RooFit::LineColor(kBlack));

  double Ns = theFit->getRealPar("N_sig")->getVal();
  double Nb = theFit->getRealPar("N_bkg")->getVal();

  // plot (dashed) the bkg component
  theFit->getRealPar("N_sig")->setVal(0.);
  thePdf->plotOn(plot, RooFit::Normalization(Nb/(Ns+Nb)),RooFit::LineColor(kBlack),RooFit::LineStyle(kDashed));

  return plot;
}

