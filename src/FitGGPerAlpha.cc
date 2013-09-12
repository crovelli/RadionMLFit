
MLOptions GetDefaultOptions() {
  MLOptions opts;
  opts.addBoolOption("lowMass",  "Fit low mass region",  kFALSE);

  return opts;
}

// declarations
RooDataSet *getDataSet(const char *rootfile, const char *treename, bool weightedDataset);
RooDataSet *getDataSet2(const char *rootfile, const char *treename, int category);
void FitGGPerAlphaMC(int region, int category);   
void FitGGPerAlphaData(int region, int category);   
void PlotGGPerAlphaMC(int region, int category, int nbins);   
void PlotGGPerAlphaData(int region, int category, int nbins);
void PlotGGPerAlpha_generation(int nbins, int category);    
void PlotGGPerAlpha_writeCorrectedWS_lowMass(int category);    
void PlotGGPerAlpha_writeCorrectedWS_highMass(int category);    
void PlotGGPerAlphaAll(int nbins);

// function calling everything else
void runAlphaStudy() {

  // Various fit options...
  MLOptions opts = GetDefaultOptions();
  cout << endl;
  if(opts.getBoolVal("lowMass"))
    cout << "THIS IS LOW MASS" << endl; 
  else 
    cout << "THIS IS HIGH MASS" << endl; 

  cout << endl;
  cout << endl;

  /*
  cout << "Fit to data: low sideband - no categorization"  << endl; 
  FitGGPerAlphaData(0,2);
  cout << "Fit to data: high sideband - no categorization" << endl; 
  FitGGPerAlphaData(1,2);
  cout << "Fit to data: signal region - no categorization" << endl; 
  FitGGPerAlphaData(2,2);
  cout << endl;

  cout << "Check fit to data: low sideband - no categorization"  << endl;
  PlotGGPerAlphaData(0,2,19);
  cout << "Check fit to data: high sideband - no categorization" << endl;
  PlotGGPerAlphaData(1,2,19);
  cout << "Check fit to data: signal region - no categorization" << endl;
  PlotGGPerAlphaData(2,2,19);
  cout << endl;


  cout << "Fit to data: low sideband - btag category=1"  << endl; 
  FitGGPerAlphaData(0,1);
  cout << "Fit to data: high sideband - btag category=1" << endl; 
  FitGGPerAlphaData(1,1);
  cout << "Fit to data: signal region - btag category=1" << endl; 
  FitGGPerAlphaData(2,1);
  cout << endl;

  cout << "Check fit to data: low sideband - btag category=1"  << endl;                                                  
  PlotGGPerAlphaData(0,1,19); 
  cout << "Check fit to data: high sideband - btag category=1" << endl;
  PlotGGPerAlphaData(1,1,19);
  cout << "Check fit to data: signal region - btag category=1" << endl; 
  PlotGGPerAlphaData(2,1,19);
  cout << endl;

  cout << "Fit to data: low sideband - btag category=2"  << endl; 
  FitGGPerAlphaData(0,0);
  cout << "Fit to data: high sideband - btag category=2" << endl; 
  FitGGPerAlphaData(1,0);
  cout << "Fit to data: signal region - btag category=2" << endl; 
  FitGGPerAlphaData(2,0);
  cout << endl;

  cout << "Check fit to data: low sideband - btag category=2"  << endl; 
  PlotGGPerAlphaData(0,0,19);  
  cout << "Check fit to data: high sideband - btag category=2" << endl;
  PlotGGPerAlphaData(1,0,19);                                         
  cout << "Check fit to data: signal region - btag category=2" << endl;
  PlotGGPerAlphaData(2,0,19); 
  cout << endl;

  cout << endl;

  cout << "Fit to mc: low sideband - no categorization"  << endl; 
  FitGGPerAlphaMC(0,2);
  cout << "Fit to mc: high sideband - no categorization" << endl; 
  FitGGPerAlphaMC(1,2);
  cout << "Fit to mc: signal region - no categorization" << endl; 
  FitGGPerAlphaMC(2,2);
  cout << endl;

  cout << "Check fit to mc: low sideband - no categorization"  << endl;
  PlotGGPerAlphaMC(0,2,19);
  cout << "Check fit to mc: high sideband - no categorization" << endl;
  PlotGGPerAlphaMC(1,2,19);
  cout << "Check fit to mc: signal region - no categorization" << endl;
  PlotGGPerAlphaMC(2,2,19);
  cout << endl;

  cout << "Fit to mc: low sideband - btag category=1"  << endl; 
  FitGGPerAlphaMC(0,1);
  cout << "Fit to mc: high sideband - btag category=1" << endl; 
  FitGGPerAlphaMC(1,1);
  cout << "Fit to mc: signal region - btag category=1" << endl; 
  FitGGPerAlphaMC(2,1);
  cout << endl;

  cout << "Check fit to mc: low sideband - btag category=1"  << endl; 
  PlotGGPerAlphaMC(0,1,19);
  cout << "Check fit to mc: high sideband - btag category=1" << endl;
  PlotGGPerAlphaMC(1,1,19);
  cout << "Check fit to mc: signal region - btag category=1" << endl;
  PlotGGPerAlphaMC(2,1,19); 
  cout << endl;

  cout << "Fit to mc: low sideband - btag category=2"  << endl; 
  FitGGPerAlphaMC(0,0);
  cout << "Fit to mc: high sideband - btag category=2" << endl; 
  FitGGPerAlphaMC(1,0);
  cout << "Fit to mc: signal region - btag category=2" << endl; 
  FitGGPerAlphaMC(2,0);
  cout << endl;

  cout << "Check fit to mc: low sideband - btag category=2"  << endl; 
  PlotGGPerAlphaMC(0,0,19);                                                                                                                
  cout << "Check fit to mc: high sideband - btag category=2" << endl;
  PlotGGPerAlphaMC(1,0,19);
  cout << "Check fit to mc: signal region - btag category=2" << endl;
  PlotGGPerAlphaMC(2,0,19);  
  cout << endl;

  cout << endl;
  */

  /*
  cout << "Plot with toys generation - no categorization" << endl;
  PlotGGPerAlpha_generation(19, 2);
  cout << "Plot with toys generation - btag category=1"   << endl;
  PlotGGPerAlpha_generation(19, 1);
  cout << "Plot with toys generation - btag category=2"   << endl;
  PlotGGPerAlpha_generation(19, 0);
  */

  cout << endl;
  cout << "Preparing new workspace for background" << endl;
  if(opts.getBoolVal("lowMass")) {
    //PlotGGPerAlpha_writeCorrectedWS_lowMass(2);    
    //PlotGGPerAlpha_writeCorrectedWS_lowMass(1);    
    //PlotGGPerAlpha_writeCorrectedWS_lowMass(0);
  }    
  else {
    //PlotGGPerAlpha_writeCorrectedWS_highMass(2);      
    // PlotGGPerAlpha_writeCorrectedWS_highMass(1);      
    //PlotGGPerAlpha_writeCorrectedWS_highMass(0);      
  }


  cout << endl;
  cout << endl;
  cout << "Now merging everything in a single WS" << endl;
  RooWorkspace *wAllAll = new RooWorkspace("w_all","w_all");

  char toSave[300];
  for (int cat=0; cat<3; cat++) {

    if(opts.getBoolVal("lowMass")) sprintf(toSave,"lowMassWS_cat%d.root",cat);
    else sprintf(toSave,"highMassWS_cat%d.root",cat);

    TFile *fileCatX = new TFile(toSave);
    RooWorkspace *wsCatX = (RooWorkspace*)fileCatX->Get("w_all1cat");

    sprintf(toSave,"MggjjBkg_cat%d",cat);
    if(opts.getBoolVal("lowMass")) {
      RooLandau *pdfL = wsCatX->pdf(toSave);
      wAllAll->import(*pdfL);
    } else {
      RooExponential *pdfH = wsCatX->pdf(toSave);
      wAllAll->import(*pdfH);
    }

    sprintf(toSave,"data_obs_cat%d",cat);
    RooDataHist *dataB = wsCatX->data(toSave);

    sprintf(toSave,"Data_cat%d",cat);
    RooDataHist *dataU = wsCatX->data(toSave);

    wAllAll->import(*dataU);
    wAllAll->import(*dataB);
  }
  std::cout << "done with importing everything in the merged workspace" << std::endl;
  if(opts.getBoolVal("lowMass")) wAllAll->writeToFile("lowMassWS_all.root");
  else wAllAll->writeToFile("highMassWS_all.root");
}

// preparing a roodataset
RooDataSet *getDataSet(const char *rootfile, const char *treename, bool weightedDataset) {    
  
  cout << endl;
  cout << "running getDataSet" << endl;
  cout << endl;

  if ( weightedDataset) cout << "roofitting file. Creating a weighted dataset"     << rootfile << endl;
  if (!weightedDataset) cout << "roofitting file. Creating a not-weighted dataset" << rootfile << endl;
  
  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // fit variables
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 300., 1000.);
  
  // needed bools
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory", 0.9,2.1);

  // weights
  RooRealVar* weight = new RooRealVar("weight", "weight",0,10.);

  RooArgSet setall(*massggnewvtx,*mjj,*mggjj,*btagCategory,*weight);            

  TFile *file = TFile::Open(rootfile);
  TTree *tree = (TTree*)file->Get(treename);

  RooDataSet *data;
  if(weightedDataset)
    data = new RooDataSet("myTrees","dataset",tree,setall,0,weight->GetName());
  else
    data = new RooDataSet("myTrees","dataset",tree,setall,0);

  data->Print();

  return data;
}

// preparing a roodataset for the final ws - I don't manage in changing the name....
RooDataSet *getDataSet2(const char *rootfile, const char *treename, int category) {    
  
  cout << endl;
  cout << "running getDataSet2" << endl;
  cout << "roofitting file. Creating a not-weighted dataset for the last step" << rootfile << endl;
  cout << endl;
  
  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // fit variables
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 300., 1000.);
  
  // needed bools
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory", 0.9,2.1);

  // weights
  RooRealVar* weight = new RooRealVar("weight", "weight",0,10.);

  RooArgSet setall(*massggnewvtx,*mjj,*mggjj,*btagCategory,*weight);            

  TFile *file = TFile::Open(rootfile);
  TTree *tree = (TTree*)file->Get(treename);

  char ntsHere[300];
  sprintf(ntsHere,"Data_cat%d",category);
  RooDataSet *data = new RooDataSet(ntsHere,ntsHere,tree,setall,0);

  data->Print();

  return data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FitGGPerAlphaMC(int region, int category) {   

  cout << "Fit to mc. The region is " << region << ", the btag category is " << category << endl;

  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);   
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 300., 1000.);
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory", -0.9, 2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(mggjj);
  theFit.AddFlatFileColumn(btagCategory);

  // define a fit model
  theFit.addModel("myFit", "HtoGG");
  
  // define species
  theFit.addSpecies("myFit", "bkg", "Bkg   Component");
  
  // mLL PDF - background
  if(opts.getBoolVal("lowMass"))
    theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Landau", "bkg_Mass");   
  else 
    theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Expo", "bkg_Mass");   

  // Load the data
  char datasetnameB[200];
  sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_DiPhoton_8TeV_default_CSV.root");  
  
  char datasetnameS[200];
  sprintf(datasetnameS, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_Radion_M-300_madgraph_default_CSV.root");

  char treename[100];
  sprintf(treename,"myTrees");   

  RooDataSet *data = getDataSet(datasetnameB,  treename, true);

  // selection 
  if(opts.getBoolVal("lowMass")) {

    if (category==2) {        // no btag category - chiara: qui metto i tagli mjj come per 1btag, che sono piu' loose
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");

    } else if (category==1) { // btag category == 1: 1 btagged jet
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");

    } else if (category==0) { // btag category == 0: 2 btagged jets
                              // chiara: i tagli erano 95/150, ma troppo poca statistica. Metto come per 1btag  
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
    }

  }  else {

    if (category==2) {        // no btag category
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");

    } else if (category==1) { // btag category == 1: 1 btagged jet
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");

    } else if (category==0) { // btag category == 0: 2 btagged jets
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
    }
  }

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");
  
  // Initialize the fit
  char fitconfig[200];
  if(opts.getBoolVal("lowMass")) {
    if (region==0)      sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_LS.config");    
    else if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_HS.config");    
    else if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_SR.config");    
  } else {
    if (region==0)      sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_LS.config");    
    else if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_HS.config");    
    else if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_SR.config");    
  }
  theFit.initialize(fitconfig);
  
  // Print Fit configuration 
  myPdf->getParameters(data)->selectByAttrib("Constant",kTRUE)->Print("V");  
  myPdf->getParameters(data)->selectByAttrib("Constant",kFALSE)->Print("V");

  // Fit to low/high sideband or signal region
  cout << endl;
  if (region==0)      cout << "Fit to MC: low sideband"  << endl;
  else if (region==1) cout << "Fit to MC: high sideband" << endl;
  else if (region==2) cout << "Fit to MC: signal region" << endl;
  cout << endl;
  RooFitResult *fitres =  myPdf->fitTo(*data,
				       RooFit::ConditionalObservables(theFit.getNoNormVars("myFit")),
				       RooFit::FitOptions("MHTER"),
				       RooFit::NumCPU(4),
				       RooFit::SumW2Error(kTRUE));   // chiara?
  fitres->Print("V");

  if (category==2) {
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat2_mc.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat2_mc.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat2_mc.config");  

  } else if (category==1) {
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat1_mc.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat1_mc.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat1_mc.config");  

  } else if (category==0) {
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat0_mc.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat0_mc.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat0_mc.config");  
  }


  TFile *fileOut;
  if (category==2) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat2_mc.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat2_mc.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat2_mc.root","RECREATE");

  } else if (category==1) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat1_mc.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat1_mc.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat1_mc.root","RECREATE");

  } else if (category==0) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat0_mc.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat0_mc.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat0_mc.root","RECREATE");
  }

  fileOut->cd();
  fitres->Write();
  fileOut->Close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FitGGPerAlphaData(int region, int category) {   

  cout << "Fit to data. The region is " << region << ", the btag category is " << category << endl;

  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);   
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 300., 1000.);
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory",  -0.9,2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(mggjj);
  theFit.AddFlatFileColumn(btagCategory);

  // define a fit model
  theFit.addModel("myFit", "HtoGG");
  
  // define species
  theFit.addSpecies("myFit", "bkg", "Bkg   Component");
  
  // mLL PDF - background
  if(opts.getBoolVal("lowMass"))
    theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Landau", "bkg_Mass");   
  else 
    theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Expo", "bkg_Mass");   

  // Load the data
  char datasetnameB[200];
  sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_Data2012_default_CSV.root");   
  
  char datasetnameS[200];
  sprintf(datasetnameS, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_Radion_M-300_madgraph_default_CSV.root");

  char treename[100];
  sprintf(treename,"myTrees");   

  RooDataSet *data = getDataSet(datasetnameB, treename, false);

  // selection 
  if(opts.getBoolVal("lowMass")) {
    
    if(category==2) {  
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      
    } else if (category==1) {
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      
    } else if (category==0) {
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
    }
  } else {

    if(category==2) {
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300"); 
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300"); 
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300"); 

    } else if (category==1) {
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1"); 
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1"); 
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1"); 

    } else if (category==0) {
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2"); 
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2"); 
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2"); 
    }
  }

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");
  
  // Initialize the fit
  char fitconfig[200];
  if(opts.getBoolVal("lowMass")) {
    if (region==0)      sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_LS.config");    
    else if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_HS.config");    
    else if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_SR.config");    
  } else {
    if (region==0)      sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_LS.config");    
    else if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_HS.config");    
    else if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_SR.config");    
  }
  theFit.initialize(fitconfig);
  
  // Print Fit configuration 
  myPdf->getParameters(data)->selectByAttrib("Constant",kTRUE)->Print("V");  
  myPdf->getParameters(data)->selectByAttrib("Constant",kFALSE)->Print("V");

  // Fit to low/high sideband or signal region
  cout << endl;
  if (region==0)      cout << "Fit to data: Low sideband"  << endl;
  else if (region==1) cout << "Fit to data: High sideband" << endl;
  else if (region==2) cout << "Fit to data: Signal region" << endl;
  cout << endl;

  RooFitResult *fitres =  myPdf->fitTo(*data,
				       RooFit::ConditionalObservables(theFit.getNoNormVars("myFit")),
				       RooFit::FitOptions("MHTER"),
				       RooFit::NumCPU(4),
				       RooFit::SumW2Error(kTRUE));   // chiara?
  fitres->Print("V");

  if (category==2) {
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat2_data.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat2_data.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat2_data.config");  

  } else if (category==1) { 
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat1_data.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat1_data.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat1_data.config");  

  } else if (category==0) {
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat0_data.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat0_data.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat0_data.config");  
  }

  TFile *fileOut;
  if (category==2) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat2_data.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat2_data.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat2_data.root","RECREATE");

  } else if (category==1) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat1_data.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat1_data.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat1_data.root","RECREATE");

  } else if (category==0) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat0_data.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat0_data.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat0_data.root","RECREATE");
  }

  fileOut->cd();
  fitres->Write();
  fileOut->Close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlotGGPerAlpha_generation(int nbins, int category) {    
  
  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // Set the random number seed for toys generation
  TDatime *now = new TDatime();
  int today    = now->GetDate();
  int clock    = now->GetTime();
  int seed     = today+clock+65539;
  RooRandom::randomGenerator()->SetSeed(seed);

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 300., 1000.);
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory", -0.9,2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(mggjj);
  theFit.AddFlatFileColumn(btagCategory);

  // define a fit model
  theFit.addModel("myFit", "HtoGG");
  
  // define species
  theFit.addSpecies("myFit", "bkg", "Bkg   Component");
  
  // mLL PDF - background
  if(opts.getBoolVal("lowMass"))
    theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Landau", "bkg_Mass");      
  else
    theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Expo", "bkg_Mass");      

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // initializations for the plots
  TCanvas *c = new TCanvas("c","fitResult");

  RooRealVar* Var = theFit.RealObservable("mggjj");           
  double min      = Var->getMin();
  double max      = Var->getMax();
  RooPlot *plot   = Var->frame(min,max,nbins);
  
  // the total likelihood
  RooAbsPdf *thePdfL, *thePdfH, *thePdfS;

  // Reading the fit results for sidebands and signal region. Make toy generations
  RooArgSet setqui(*mggjj);

  cout << endl;
  cout << "Low sideband" << endl;
  if (category==2)      theFit.initialize("fitres/fitBackground_lowSideband_cat2_mc.config");  
  else if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_mc.config");  
  else if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_mc.config");  
  thePdfL = theFit.getPdf("myFit");
  thePdfL->plotOn(plot, RooFit::LineColor(kBlue));
  RooDataSet *genDataL = thePdfL->generate(setqui,2000000,kTRUE,kFALSE);

  cout << endl;
  cout << "High sideband" << endl;
  if (category==2)      theFit.initialize("fitres/fitBackground_highSideband_cat2_mc.config");  
  else if (category==1) theFit.initialize("fitres/fitBackground_highSideband_cat1_mc.config");  
  else if (category==0) theFit.initialize("fitres/fitBackground_highSideband_cat0_mc.config");  
  thePdfH = theFit.getPdf("myFit");
  thePdfH->plotOn(plot, RooFit::LineColor(kGreen));
  RooDataSet *genDataH = thePdfH->generate(setqui,2000000,kTRUE,kFALSE);

  cout << endl;
  cout << "Signal region" << endl;
  if (category==2)      theFit.initialize("fitres/fitBackground_signalRegion_cat2_mc.config");  
  else if (category==1) theFit.initialize("fitres/fitBackground_signalRegion_cat1_mc.config");  
  else if (category==0) theFit.initialize("fitres/fitBackground_signalRegion_cat0_mc.config");  

  thePdfS = theFit.getPdf("myFit");
  thePdfS->plotOn(plot, RooFit::LineColor(kRed));
  RooDataSet *genDataS = thePdfS->generate(setqui,2000000,kTRUE,kFALSE);
  cout << endl;
  cout << endl;

  // plot from the original pdfs
  TCanvas *myC = new TCanvas("myC","",1);
  myC->cd();
  plot->SetYTitle("Events");
  plot->Draw();
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat2.png");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat1.png");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat0.png");  

  // Trees from the previous toys
  TTree *treeGenDataL  = dataset2tree(genDataL);
  TH1F *h1_mggjj_genL;
  if(opts.getBoolVal("lowMass"))
    h1_mggjj_genL = new TH1F("h1_mggjj_genL","h1_mggjj_genL",50,200.,700.);
  else 
    h1_mggjj_genL = new TH1F("h1_mggjj_genL","h1_mggjj_genL",60,300.,1000.);    
  h1_mggjj_genL->Sumw2();
  treeGenDataL->Project("h1_mggjj_genL","mggjj");

  TTree *treeGenDataH = dataset2tree(genDataH);
  TH1F *h1_mggjj_genH;
  if(opts.getBoolVal("lowMass"))
    h1_mggjj_genH = new TH1F("h1_mggjj_genH","h1_mggjj_genH",50,200.,700.);
  else 
    h1_mggjj_genH = new TH1F("h1_mggjj_genH","h1_mggjj_genH",60,300.,1000.);    
  h1_mggjj_genH->Sumw2();
  treeGenDataH->Project("h1_mggjj_genH","mggjj");

  TTree *treeGenDataS = dataset2tree(genDataS);
  TH1F *h1_mggjj_genS;
  if(opts.getBoolVal("lowMass"))
    h1_mggjj_genS = new TH1F("h1_mggjj_genS","h1_mggjj_genS",50,200.,700.);
  else 
    h1_mggjj_genS = new TH1F("h1_mggjj_genS","h1_mggjj_genS",60,300.,1000.);    
  h1_mggjj_genS->Sumw2();
  treeGenDataS->Project("h1_mggjj_genS","mggjj");


  // plot from the generated datasets
  h1_mggjj_genL->SetLineColor(kBlue);
  h1_mggjj_genH->SetLineColor(kGreen);
  h1_mggjj_genS->SetLineColor(kRed);

  h1_mggjj_genL->Scale(1./(h1_mggjj_genL->Integral()));
  h1_mggjj_genH->Scale(1./(h1_mggjj_genH->Integral()));
  h1_mggjj_genS->Scale(1./(h1_mggjj_genS->Integral()));

  h1_mggjj_genL->Draw("hist");
  h1_mggjj_genH->Draw("samehist");
  h1_mggjj_genS->Draw("samehist");
  if (category==2)      myC->SaveAs("fitres/mGGJJ_histosObtainedFromMcToys_cat2.png");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_histosObtainedFromMcToys_cat1.png");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_histosObtainedFromMcToys_cat0.png");  


  // now ratio of the histos from toys
  TH1F *h1_mggjj_alphaFromL = h1_mggjj_genS->Clone("h1_mggjj_alphaFromL");                                                 
  h1_mggjj_alphaFromL->Divide(h1_mggjj_genL);                                                                                
  h1_mggjj_alphaFromL->GetXaxis()->SetTitle("alpha (from low)"); 
  h1_mggjj_alphaFromL->DrawNormalized("hist");
  h1_mggjj_alphaFromL->SetLineColor(kBlue);
  if (category==2)      myC->SaveAs("fitres/alphaH_fromLowSideband_cat2.png");
  else if (category==1) myC->SaveAs("fitres/alphaH_fromLowSideband_cat1.png");
  else if (category==0) myC->SaveAs("fitres/alphaH_fromLowSideband_cat0.png");

  TH1F *h1_mggjj_alphaFromH = h1_mggjj_genS->Clone("h1_mggjj_alphaFromH");                                                 
  h1_mggjj_alphaFromH->Divide(h1_mggjj_genH);                                                                                
  h1_mggjj_alphaFromH->GetXaxis()->SetTitle("alpha (from high)"); 
  h1_mggjj_alphaFromH->SetLineColor(kGreen);
  h1_mggjj_alphaFromH->DrawNormalized("hist");
  if (category==2)      myC->SaveAs("fitres/alphaH_fromHighSideband_cat2.png");
  else if (category==1) myC->SaveAs("fitres/alphaH_fromHighSideband_cat1.png");
  else if (category==0) myC->SaveAs("fitres/alphaH_fromHighSideband_cat0.png");
  
  // saving the histos
  TFile *myOutFile;
  if (category==2)       myOutFile = new TFile("fitres/mGGJJ_fromGeneration_cat2.root","RECREATE");
  else if (category==1)  myOutFile = new TFile("fitres/mGGJJ_fromGeneration_cat1.root","RECREATE");
  else if (category==0)  myOutFile = new TFile("fitres/mGGJJ_fromGeneration_cat0.root","RECREATE");
  plot->Write();
  h1_mggjj_genL->Write();
  h1_mggjj_genH->Write();
  h1_mggjj_genS->Write();
  h1_mggjj_alphaFromL->Write();
  h1_mggjj_alphaFromH->Write();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlotGGPerAlpha_writeCorrectedWS_lowMass(int category) {    
  
  cout << "preparing workspace at low mass, category = " << category << endl;

  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);
  RooRealVar* mggjj        = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 200., 700.);   
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory",            -0.9, 2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(mggjj);
  theFit.AddFlatFileColumn(btagCategory);

  // define a fit model
  theFit.addModel("myFit", "HtoGG");
  theFit.addSpecies ("myFit", "bkg", "Bkg   Component");
  theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Landau", "bkg_Mass");      
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // Now reading the previous fit results for sidebands and signal region (data and mc)
  RooAbsPdf *thePdfLMc, *thePdfHMc, *thePdfSMc;
  RooAbsPdf *thePdfLData;
  RooArgSet setqui(*mggjj);

  // initializations for the plots
  TCanvas *c = new TCanvas("c","fitResult");
  RooRealVar* Var = theFit.RealObservable("mggjj");           
  double min      = Var->getMin();
  double max      = Var->getMax();
  RooPlot *plot   = Var->frame(min,max,19);

  cout << endl;
  cout << "Reading results from low sideband fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_lowSideband_cat2_mc.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_mc.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_mc.config");  
  thePdfLMc = theFit.getPdf("myFit");
  thePdfLMc->plotOn(plot, RooFit::LineColor(kBlue));
  (thePdfLMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_LSmc;
  if (category==2) file_RFR_LSmc = new TFile("fitres/fitRes_region0_cat2_mc.root");
  if (category==1) file_RFR_LSmc = new TFile("fitres/fitRes_region0_cat1_mc.root");
  if (category==0) file_RFR_LSmc = new TFile("fitres/fitRes_region0_cat0_mc.root");
  RooFitResult *results_LSmc       = (RooFitResult*)file_RFR_LSmc->Get("nll_myFit_myTrees");
  RooRealVar* mean_fitresult_LSmc  = (RooRealVar*)( (results_LSmc->floatParsFinal()).find("bkg_Mass_mean") );
  RooRealVar* sigma_fitresult_LSmc = (RooRealVar*)( (results_LSmc->floatParsFinal()).find("bkg_Mass_sigma") );
  float mean_LSmc     = mean_fitresult_LSmc->getVal(); 
  float meanErr_LSmc  = mean_fitresult_LSmc->getError(); 
  float sigma_LSmc    = sigma_fitresult_LSmc->getVal(); 
  float sigmaErr_LSmc = sigma_fitresult_LSmc->getError(); 

  cout << endl;
  cout << "Reading results from high sideband fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_highSideband_cat2_mc.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_highSideband_cat1_mc.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_highSideband_cat0_mc.config");  
  thePdfHMc = theFit.getPdf("myFit");
  thePdfHMc->plotOn(plot, RooFit::LineColor(kGreen));
  (thePdfHMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_HSmc;
  if (category==2) file_RFR_HSmc = new TFile("fitres/fitRes_region1_cat2_mc.root");
  if (category==1) file_RFR_HSmc = new TFile("fitres/fitRes_region1_cat1_mc.root");
  if (category==0) file_RFR_HSmc = new TFile("fitres/fitRes_region1_cat0_mc.root");
  RooFitResult *results_HSmc       = (RooFitResult*)file_RFR_HSmc->Get("nll_myFit_myTrees");
  RooRealVar* mean_fitresult_HSmc  = (RooRealVar*)( (results_HSmc->floatParsFinal()).find("bkg_Mass_mean") );
  RooRealVar* sigma_fitresult_HSmc = (RooRealVar*)( (results_HSmc->floatParsFinal()).find("bkg_Mass_sigma") );
  float mean_HSmc     = mean_fitresult_HSmc->getVal(); 
  float meanErr_HSmc  = mean_fitresult_HSmc->getError(); 
  float sigma_HSmc    = sigma_fitresult_HSmc->getVal(); 
  float sigmaErr_HSmc = sigma_fitresult_HSmc->getError(); 

  cout << endl;
  cout << "Reading results from signal region fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_signalRegion_cat2_mc.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_signalRegion_cat1_mc.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_signalRegion_cat0_mc.config");  
  thePdfSMc = theFit.getPdf("myFit");
  thePdfSMc->plotOn(plot, RooFit::LineColor(kRed));
  (thePdfSMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_SRmc;
  if(category==2) file_RFR_SRmc = new TFile("fitres/fitRes_region2_cat2_mc.root");
  if(category==1) file_RFR_SRmc = new TFile("fitres/fitRes_region2_cat1_mc.root");
  if(category==0) file_RFR_SRmc = new TFile("fitres/fitRes_region2_cat0_mc.root");
  RooFitResult *results_SRmc       = (RooFitResult*)file_RFR_SRmc->Get("nll_myFit_myTrees");
  RooRealVar* mean_fitresult_SRmc  = (RooRealVar*)( (results_SRmc->floatParsFinal()).find("bkg_Mass_mean") );
  RooRealVar* sigma_fitresult_SRmc = (RooRealVar*)( (results_SRmc->floatParsFinal()).find("bkg_Mass_sigma") );
  float mean_SRmc     = mean_fitresult_SRmc->getVal(); 
  float meanErr_SRmc  = mean_fitresult_SRmc->getError(); 
  float sigma_SRmc    = sigma_fitresult_SRmc->getVal(); 
  float sigmaErr_SRmc = sigma_fitresult_SRmc->getError(); 

  // plot from the original pdfs
  TH1F *myH_fuffaLR = new TH1F("myH_fuffaLR","myH_fuffaLR",100,0,100);
  TH1F *myH_fuffaHR = new TH1F("myH_fuffaHR","myH_fuffaHR",100,0,100);
  TH1F *myH_fuffaSR = new TH1F("myH_fuffaSR","myH_fuffaSR",100,0,100);
  myH_fuffaLR->SetLineColor(kBlue);
  myH_fuffaHR->SetLineColor(kGreen);
  myH_fuffaSR->SetLineColor(kRed);
  myH_fuffaLR->SetLineWidth(2);
  myH_fuffaHR->SetLineWidth(2);
  myH_fuffaSR->SetLineWidth(2);
  TLegend *leg;
  leg = new TLegend(0.5,0.5,0.75,0.75);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.05);
  leg->SetFillColor(0);
  leg->AddEntry(myH_fuffaLR, "low mgg sideband",  "l");
  leg->AddEntry(myH_fuffaHR, "high mgg sideband", "l");
  leg->AddEntry(myH_fuffaSR, "mgg signal region", "l");
  TCanvas *myC = new TCanvas("myC","",1);
  myC->cd();
  plot->SetYTitle("Events");
  plot->Draw();
  leg->Draw();
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat2.png");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat1.png");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat0.png");  

  cout << endl;
  cout << "Reading results from low sideband fit in Data" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_lowSideband_cat2_data.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_data.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_data.config");  
  thePdfLData = theFit.getPdf("myFit");
  (thePdfLData->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_LSdata;
  if (category==2) file_RFR_LSdata = new TFile("fitres/fitRes_region0_cat2_data.root"); 
  if (category==1) file_RFR_LSdata = new TFile("fitres/fitRes_region0_cat1_data.root"); 
  if (category==0) file_RFR_LSdata = new TFile("fitres/fitRes_region0_cat0_data.root"); 
  RooFitResult *results_LSdata       = (RooFitResult*)file_RFR_LSdata->Get("nll_myFit_myTrees");  
  RooRealVar* mean_fitresult_LSdata  = (RooRealVar*)( (results_LSdata->floatParsFinal()).find("bkg_Mass_mean") );
  RooRealVar* sigma_fitresult_LSdata = (RooRealVar*)( (results_LSdata->floatParsFinal()).find("bkg_Mass_sigma") );
  float mean_LSdata     = mean_fitresult_LSdata->getVal(); 
  float meanErr_LSdata  = mean_fitresult_LSdata->getError(); 
  float sigma_LSdata    = sigma_fitresult_LSdata->getVal(); 
  float sigmaErr_LSdata = sigma_fitresult_LSdata->getError(); 
  cout << endl;

  cout << endl;
  cout << endl;
  cout << "first summary:" << endl;
  cout << "Data, low sideband: mean = " << mean_LSdata << " +/- " << meanErr_LSdata << ", sigma = " << sigma_LSdata << " +/- " << sigmaErr_LSdata << endl; 
  cout << "MC, low sideband: mean = "   << mean_LSmc   << " +/- " << meanErr_LSmc   << ", sigma = " << sigma_LSmc   << " +/- " << sigmaErr_LSmc   << endl; 
  cout << "MC, high sideband: mean = "  << mean_HSmc   << " +/- " << meanErr_HSmc   << ", sigma = " << sigma_HSmc   << " +/- " << sigmaErr_HSmc   << endl; 
  cout << "MC, signal region: mean = "  << mean_SRmc   << " +/- " << meanErr_SRmc   << ", sigma = " << sigma_SRmc   << " +/- " << sigmaErr_SRmc   << endl; 
  cout << endl;
  cout << endl;

  char nameToSave[300];

  // Now replacing the values from sideband fit with alpha-corrected ones
  // and preparing a new PDF to be saved in the workspace for the fit
  float myCorrMean  = mean_LSdata*(mean_SRmc/mean_LSmc);
  float myCorrSigma = sigma_LSdata*(sigma_SRmc/sigma_LSmc);
  cout << "mean after correction = " << myCorrMean << ", sigma after correction = " << myCorrSigma << endl;

  float mPars[3]={myCorrMean, 0,2000};
  float sPars[3]={myCorrSigma,0,2000};

  sprintf(nameToSave,"mggjj_bkg_mean_cat%d",category);
  RooRealVar mean (nameToSave, nameToSave, mPars[0], mPars[1], mPars[2]);
  sprintf(nameToSave,"mggjj_bkg_sigma_cat%d",category);
  RooRealVar sigma(nameToSave, nameToSave, sPars[0], sPars[1], sPars[2]); 
  mean.setConstant(kTRUE);
  sigma.setConstant(kTRUE);
  
  sprintf(nameToSave,"MggjjBkg_cat%d",category);
  RooAbsPdf *landau = new RooLandau(nameToSave, nameToSave, *mggjj, mean, sigma);
  sprintf(nameToSave,"mggjj_bkg_mean_cat%d",category);
  float myMeanControllo   = (landau->getParameters(setqui))->getRealValue(nameToSave);
  sprintf(nameToSave,"mggjj_bkg_sigma_cat%d",category);
  float mySigmaControllo  = (landau->getParameters(setqui))->getRealValue(nameToSave);
  cout << "for check - must be the same as above: " << myMeanControllo << " " << mySigmaControllo << endl;
  cout << endl;
  
  // Now loading the data dataset (signal region) to be saved in the workspace
  char datasetnameB[200];
  sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_Data2012_default_CSV.root");   
  char treename[100];
  sprintf(treename,"myTrees");
  RooDataSet *data = getDataSet2(datasetnameB, treename, category);

  if (category==0) 
    data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1) 
    data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2) 
    data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");

  // convert it into a roodatahist - chiara: come capisco i bin?? 
  RooArgSet setqui2(*mggjj);
  sprintf(nameToSave,"data_obs_cat%d",category);
  RooDataHist dataBinned(nameToSave, nameToSave, setqui2, *data);  

  // And finally saving everything in the workspace
  RooWorkspace *wAll = new RooWorkspace("w_all1cat","w_all1cat");
  wAll->import(*landau);
  wAll->import(dataBinned);
  wAll->import(*data);

  cout << endl;
  cout << endl;
  std::cout << "done with importing background pdfs" << std::endl;
  sprintf(nameToSave,"lowMassWS_cat%d.root",category);
  wAll->writeToFile(nameToSave);

  wAll->Print();

  /*
  RooPlot *plot2 = Var->frame(min,max,25);
  dataBlind->plotOn(plot2, RooFit::MarkerStyle(20));
  // landau->plotOn(plot2, RooFit::LineColor(kAzure), RooFit::Normalization(1000,RooAbsReal::NumEvent));  // chiara
  landau->plotOn(plot2, RooFit::LineColor(kAzure));
  TCanvas *myC2 = new TCanvas("myC2","",1);
  myC2->cd();
  plot2->SetYTitle("Events");
  plot2->Draw();
  if      (category==2) myC->SaveAs("fitres/finalPlot_cat2_blind.png");  
  else if (category==1) myC->SaveAs("fitres/finalPlot_cat1_blind.png");  
  else if (category==0) myC->SaveAs("fitres/finalPlot_cat0_blind.png");  
  */
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlotGGPerAlpha_writeCorrectedWS_highMass(int category) {    
  
  cout << "preparing workspace at high mass, category = " << category << endl;

  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);
  RooRealVar* mggjj        = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 300., 1000.);   
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory",            -0.9, 2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(mggjj);
  theFit.AddFlatFileColumn(btagCategory);

  // define a fit model
  theFit.addModel("myFit", "HtoGG");
  theFit.addSpecies ("myFit", "bkg", "Bkg   Component");
  theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Expo", "bkg_Mass");      
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // Now reading the previous fit results for sidebands and signal region (data and mc)
  RooAbsPdf *thePdfLMc, *thePdfHMc, *thePdfSMc;
  RooAbsPdf *thePdfLData;
  RooArgSet setqui(*mggjj);

  // initializations for the plots
  TCanvas *c = new TCanvas("c","fitResult");
  RooRealVar* Var = theFit.RealObservable("mggjj");           
  double min      = Var->getMin();
  double max      = Var->getMax();
  RooPlot *plot   = Var->frame(min,max,19);

  cout << endl;
  cout << "Reading results from low sideband fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_lowSideband_cat2_mc.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_mc.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_mc.config");  
  thePdfLMc = theFit.getPdf("myFit");
  thePdfLMc->plotOn(plot, RooFit::LineColor(kBlue));
  (thePdfLMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_LSmc;
  if (category==2) file_RFR_LSmc = new TFile("fitres/fitRes_region0_cat2_mc.root");
  if (category==1) file_RFR_LSmc = new TFile("fitres/fitRes_region0_cat1_mc.root");
  if (category==0) file_RFR_LSmc = new TFile("fitres/fitRes_region0_cat0_mc.root");
  RooFitResult *results_LSmc     = (RooFitResult*)file_RFR_LSmc->Get("nll_myFit_myTrees");
  RooRealVar* exp_fitresult_LSmc = (RooRealVar*)( (results_LSmc->floatParsFinal()).find("bkg_Mass_exp") );
  float exp_LSmc    = exp_fitresult_LSmc->getVal(); 
  float expErr_LSmc = exp_fitresult_LSmc->getError(); 

  cout << endl;
  cout << "Reading results from high sideband fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_highSideband_cat2_mc.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_highSideband_cat1_mc.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_highSideband_cat0_mc.config");  
  thePdfHMc = theFit.getPdf("myFit");
  thePdfHMc->plotOn(plot, RooFit::LineColor(kGreen));
  (thePdfHMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_HSmc;
  if (category==2) file_RFR_HSmc = new TFile("fitres/fitRes_region1_cat2_mc.root");
  if (category==1) file_RFR_HSmc = new TFile("fitres/fitRes_region1_cat1_mc.root");
  if (category==0) file_RFR_HSmc = new TFile("fitres/fitRes_region1_cat0_mc.root");
  RooFitResult *results_HSmc     = (RooFitResult*)file_RFR_HSmc->Get("nll_myFit_myTrees");
  RooRealVar* exp_fitresult_HSmc = (RooRealVar*)( (results_HSmc->floatParsFinal()).find("bkg_Mass_exp") );
  float exp_HSmc    = exp_fitresult_HSmc->getVal(); 
  float expErr_HSmc = exp_fitresult_HSmc->getError(); 

  cout << endl;
  cout << "Reading results from signal region fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_signalRegion_cat2_mc.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_signalRegion_cat1_mc.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_signalRegion_cat0_mc.config");  
  thePdfSMc = theFit.getPdf("myFit");
  thePdfSMc->plotOn(plot, RooFit::LineColor(kRed));
  (thePdfSMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_SRmc;
  if(category==2) file_RFR_SRmc = new TFile("fitres/fitRes_region2_cat2_mc.root");
  if(category==1) file_RFR_SRmc = new TFile("fitres/fitRes_region2_cat1_mc.root");
  if(category==0) file_RFR_SRmc = new TFile("fitres/fitRes_region2_cat0_mc.root");
  RooFitResult *results_SRmc     = (RooFitResult*)file_RFR_SRmc->Get("nll_myFit_myTrees");
  RooRealVar* exp_fitresult_SRmc = (RooRealVar*)( (results_SRmc->floatParsFinal()).find("bkg_Mass_exp") );
  float exp_SRmc    = exp_fitresult_SRmc->getVal(); 
  float expErr_SRmc = exp_fitresult_SRmc->getError(); 

  // plot from the original pdfs
  TH1F *myH_fuffaLR = new TH1F("myH_fuffaLR","myH_fuffaLR",100,0,100);
  TH1F *myH_fuffaHR = new TH1F("myH_fuffaHR","myH_fuffaHR",100,0,100);
  TH1F *myH_fuffaSR = new TH1F("myH_fuffaSR","myH_fuffaSR",100,0,100);
  myH_fuffaLR->SetLineColor(kBlue);
  myH_fuffaHR->SetLineColor(kGreen);
  myH_fuffaSR->SetLineColor(kRed);
  myH_fuffaLR->SetLineWidth(2);
  myH_fuffaHR->SetLineWidth(2);
  myH_fuffaSR->SetLineWidth(2);
  TLegend *leg;
  leg = new TLegend(0.5,0.5,0.75,0.75);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.05);
  leg->SetFillColor(0);
  leg->AddEntry(myH_fuffaLR, "low mgg sideband",  "l");
  leg->AddEntry(myH_fuffaHR, "high mgg sideband", "l");
  leg->AddEntry(myH_fuffaSR, "mgg signal region", "l");
  TCanvas *myC = new TCanvas("myC","",1);
  myC->cd();
  plot->SetYTitle("Events");
  plot->Draw();
  leg->Draw();
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat2.png");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat1.png");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat0.png");  

  // reading fit to data
  cout << endl;
  cout << "Reading results from low sideband fit in Data" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_lowSideband_cat2_data.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_data.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_data.config");  
  thePdfLData = theFit.getPdf("myFit");
  (thePdfLData->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_LSdata;
  if (category==2) file_RFR_LSdata = new TFile("fitres/fitRes_region0_cat2_data.root"); 
  if (category==1) file_RFR_LSdata = new TFile("fitres/fitRes_region0_cat1_data.root"); 
  if (category==0) file_RFR_LSdata = new TFile("fitres/fitRes_region0_cat0_data.root"); 
  RooFitResult *results_LSdata     = (RooFitResult*)file_RFR_LSdata->Get("nll_myFit_myTrees");  
  RooRealVar* exp_fitresult_LSdata = (RooRealVar*)( (results_LSdata->floatParsFinal()).find("bkg_Mass_exp") );
  float exp_LSdata    = exp_fitresult_LSdata->getVal(); 
  float expErr_LSdata = exp_fitresult_LSdata->getError(); 
  cout << endl;

  cout << endl;
  cout << endl;
  cout << "first summary:" << endl;
  cout << "Data, low sideband: exp = " << exp_LSdata << " +/- " << expErr_LSdata << endl;
  cout << "MC, low sideband:   exp = " << exp_LSmc   << " +/- " << expErr_LSmc   << endl;
  cout << "MC, high sideband:  exp = " << exp_HSmc   << " +/- " << expErr_HSmc   << endl;
  cout << "MC, signal region:  exp = " << exp_SRmc   << " +/- " << expErr_SRmc   << endl;
  cout << endl;
  cout << endl;

  char nameToSave[300];
  // Now replacing the values from sideband fit with alpha-corrected ones
  // and preparing a new PDF to be saved in the workspace for the fit
  float myCorrExp = exp_LSdata*(exp_SRmc/exp_LSmc);
  cout << "exp after correction = " << myCorrExp << endl;

  float ePars[3]={myCorrExp, 0, 2000};
  sprintf(nameToSave,"mggjj_bkg_exp_cat%d",category);
  RooRealVar exp (nameToSave, nameToSave, ePars[0], ePars[1], ePars[2]);
  exp.setConstant(kTRUE);
  
  sprintf(nameToSave,"MggjjBkg_cat%d",category);
  RooAbsPdf *exponential = new RooExponential(nameToSave, nameToSave, *mggjj, exp);
  sprintf(nameToSave,"mggjj_bkg_exp_cat%d",category);
  float myExpControllo = (exponential->getParameters(setqui))->getRealValue(nameToSave);
  cout << "for check - must be the same as above: " << myExpControllo << endl;
  cout << endl;
  
  // Now loading the data dataset (signal region) to be saved in the workspace
  char datasetnameB[200];
  sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_Data2012_default_CSV.root");   
  char treename[100];
  sprintf(treename,"myTrees");
  RooDataSet *data = getDataSet2(datasetnameB, treename, category);

  if (category==0) 
    data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
  else if (category==1) 
    data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
  else if (category==2) 
    data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");

  // convert it into a roodatahist - chiara: come capisco i bin?? 
  RooArgSet setqui2(*mggjj);
  sprintf(nameToSave,"data_obs_cat%d",category);
  RooDataHist dataBinned(nameToSave, nameToSave, setqui2, *data);  

  // And finally saving everything in the workspace
  RooWorkspace *wAll = new RooWorkspace("w_all1cat","w_all1cat");
  wAll->import(*exponential);
  wAll->import(dataBinned);
  wAll->import(*data);

  cout << endl;
  cout << endl;
  std::cout << "done with importing background pdfs" << std::endl;
  sprintf(nameToSave,"highMassWS_cat%d.root",category);
  wAll->writeToFile(nameToSave);

  wAll->Print();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PlotGGPerAlphaMC(int region, int category, int nbins) {

  cout << "Plot the fit results to mc. The region is " << region << ", the btag category is " << category << endl;

  MLFit theFit;

  // Various fit options... 
  MLOptions opts = GetDefaultOptions();

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 300., 1000.);
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory", -0.9, 2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(mggjj);
  theFit.AddFlatFileColumn(btagCategory);

  // define a fit model
  theFit.addModel("myFit", "HtoGG");

  // define species
  theFit.addSpecies("myFit", "bkg", "Bkg   Component");

  // mLL PDF - background 
  if(opts.getBoolVal("lowMass"))
    theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Landau", "bkg_Mass");
  else
    theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Expo", "bkg_Mass");

  // Load the data 
  char datasetnameB[200];
  sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_DiPhoton_8TeV_default_CSV.root");

  char datasetnameS[200];
  sprintf(datasetnameS, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_Radion_M-300_madgraph_default_CSV.root");

  char treename[100];
  sprintf(treename,"myTrees");

  RooDataSet *data = getDataSet(datasetnameB,  treename, true);

  // selection 
  if(opts.getBoolVal("lowMass")) {

    if (category==2) {        // no btag category                          
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");

    } else if (category==1) { // btag category == 1: 1 btagged jet 
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");

    } else if (category==0) { // btag category == 0: 2 btagged jets  
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
    }

  }  else {
    if (category==2) {        // no btag category                          
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");

    } else if (category==1) { // btag category == 1: 1 btagged jet         
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");

    } else if (category==0) { // btag category == 0: 2 btagged jets 
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
    }
  }

  bool usePoissonError=false;

  // build the fit likelihood 
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // Initialize the fit 
  char fitconfig[200];
  if(opts.getBoolVal("lowMass")) {  
    if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_LS.config");
    if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_HS.config");
    if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_SR.config");
  } else {
    if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_LS.config");
    if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_HS.config");
    if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_SR.config");
  }
  theFit.initialize(fitconfig);

  // Plots                                                                
  RooRealVar* Var = theFit.RealObservable("mggjj");
  double min=Var->getMin();
  double max=Var->getMax();
  RooPlot *plot = Var->frame(min,max,nbins);

  // plot the data  
  data->plotOn(plot, RooFit::DataError(RooAbsData::SumW2) );

  // plot the total likelihood 
  RooAbsPdf *thePdf = theFit.getPdf("myFit");

  // plot background in the full range
  TCanvas *c = new TCanvas("c","fitResult");
  thePdf->plotOn(plot, RooFit::LineColor(kBlack));
  plot->SetYTitle("Events");
  plot->Draw();

  char plotfilename[200];
  if (category==2) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_cat2.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_cat2.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_cat2.png");

  } else if (category==1) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_cat1.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_cat1.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_cat1.png");

  } else if (category==0) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_cat0.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_cat0.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_cat0.png");
  }
  c->SaveAs(plotfilename);
}

//////////////////////////////////////////////////////////////////////////////////////////////////                                                                                         
void PlotGGPerAlphaData(int region, int category, int nbins) {

  cout << "Plot the fit results to data. The region is " << region << ", the btag category is " << category << endl;

  MLFit theFit;

  // Various fit options... 
  MLOptions opts = GetDefaultOptions();

  // define the structure of the dataset  
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 300., 1000.);
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory", -0.9, 2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(mggjj);
  theFit.AddFlatFileColumn(btagCategory);

  // define a fit model
  theFit.addModel("myFit", "HtoGG");

  // define species 
  theFit.addSpecies("myFit", "bkg", "Bkg   Component");

  // mLL PDF - background
  if(opts.getBoolVal("lowMass"))
    theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Landau", "bkg_Mass");
  else
    theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Expo", "bkg_Mass");

  // Load the data 
  char datasetnameB[200];
  sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_Data2012_default_CSV.root");

  char datasetnameS[200];
  sprintf(datasetnameS, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_Radion_M-300_madgraph_default_CSV.root");

  char treename[100];
  sprintf(treename,"myTrees");

  RooDataSet *data = getDataSet(datasetnameB,  treename, false);

  // selection   
  if(opts.getBoolVal("lowMass")) {

    if (category==2) {        // no btag category 
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");

    } else if (category==1) { // btag category == 1: 1 btagged jet 
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");

    } else if (category==0) { // btag category == 0: 2 btagged jets 
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
    }
  }  else {

    if (category==2) {        // no btag category 
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");

    } else if (category==1) { // btag category == 1: 1 btagged jet 
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");

    } else if (category==0) { // btag category == 0: 2 btagged jets
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
    }
  }

  bool usePoissonError=true;

  // build the fit likelihood                                                                                                     
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // Initialize the fit   
  char fitconfig[200];
  if(opts.getBoolVal("lowMass")) {  
    if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_LS.config");
    if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_HS.config");
    if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_SR.config");
  } else {
    if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_LS.config");
    if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_HS.config");
    if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_SR.config");
  }
  theFit.initialize(fitconfig);

  // Plots 
  RooRealVar* Var = theFit.RealObservable("mggjj");
  double min=Var->getMin();
  double max=Var->getMax();
  RooPlot *plot = Var->frame(min,max,nbins);

  // plot the data
  data->plotOn(plot, RooFit::DataError(RooAbsData::SumW2) );

  // plot the total likelihood
  RooAbsPdf *thePdf = theFit.getPdf("myFit");

  // plot background in the full range 
  TCanvas *c = new TCanvas("c","fitResult");
  thePdf->plotOn(plot, RooFit::LineColor(kBlack));
  plot->SetYTitle("Events");
  plot->Draw();

  char plotfilename[200];
  if (category==2) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_cat2.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_cat2.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_cat2.png");

  } else if (category==1) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_cat1.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_cat1.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_cat1.png");

  } else if (category==0) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_cat0.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_cat0.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_cat0.png");
  }
  c->SaveAs(plotfilename);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PlotGGPerAlphaAll(int nbins) {    
  
  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // Set the random number seed for toys generation
  TDatime *now = new TDatime();
  int today    = now->GetDate();
  int clock    = now->GetTime();
  int seed     = today+clock+65539;
  RooRandom::randomGenerator()->SetSeed(seed);

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma #gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma #gammajet jet} [GeV]", 300., 1000.);
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory", -0.9,2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(mggjj);
  theFit.AddFlatFileColumn(btagCategory);

  // define a fit model
  theFit.addModel("myFit", "HtoGG");
  
  // define species
  theFit.addSpecies("myFit", "bkg", "Bkg   Component");
  
  // mLL PDF - background
  if(opts.getBoolVal("lowMass"))
    theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Landau", "bkg_Mass");      
  else
    theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Expo", "bkg_Mass");      

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // initializations for the plots
  TCanvas *c = new TCanvas("c","fitResult");
  char rootfilename[200];
  sprintf(rootfilename,"fitres/mGGJJ_Background_allFits.root");  
  TFile *output = new TFile(rootfilename,"RECREATE");   

  RooRealVar* Var = theFit.RealObservable("mggjj");           
  double min      = Var->getMin();
  double max      = Var->getMax();
  RooPlot *plot   = Var->frame(min,max,nbins);
  
  // the total likelihood
  RooAbsPdf *thePdfL, *thePdfH, *thePdfS;

  // Reading the fit results for sidebands and signal region. Make toy generations
  RooArgSet setqui(*mggjj);

  cout << endl;
  cout << "Low sideband" << endl;
  theFit.initialize("fitres/fitBackground_lowSideband.config");  
  thePdfL = theFit.getPdf("myFit");
  thePdfL->plotOn(plot, RooFit::LineColor(kBlue));
  RooDataSet *genDataL = thePdfL->generate(setqui,2000000,kTRUE,kFALSE);
  cout << endl;
  cout << endl;
  cout << "parameters for low sideband fit: " << endl;  
  (thePdfL->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_LS = new TFile("fitres/fitRes_region0.root");
  // RooFitResult *results_LS       = (RooFitResult*)file_RFR_LS->Get("nll_myFit_myTrees");
  RooFitResult *results_LS       = (RooFitResult*)file_RFR_LS->Get("nll_myFit_myTrees");
  RooRealVar* mean_fitresult_LS  = (RooRealVar*)( (results_LS->floatParsFinal()).find("bkg_Mass_mean") );
  RooRealVar* sigma_fitresult_LS = (RooRealVar*)( (results_LS->floatParsFinal()).find("bkg_Mass_sigma") );
  float mean_LS     = mean_fitresult_LS->getVal(); 
  float meanErr_LS  = mean_fitresult_LS->getError(); 
  float sigma_LS    = sigma_fitresult_LS->getVal(); 
  float sigmaErr_LS = sigma_fitresult_LS->getError(); 
  // cout << mean_LS  << " " << meanErr_LS  << endl;
  // cout << sigma_LS << " " << sigmaErr_LS << endl;

  cout << endl;
  cout << "High sideband" << endl;
  theFit.initialize("fitres/fitBackground_highSideband.config");  
  thePdfH = theFit.getPdf("myFit");
  thePdfH->plotOn(plot, RooFit::LineColor(kGreen));
  RooDataSet *genDataH = thePdfH->generate(setqui,2000000,kTRUE,kFALSE);
  cout << endl;
  cout << endl;
  cout << "parameters for high sideband fit: " << endl;  
  (thePdfH->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_HS = new TFile("fitres/fitRes_region1.root");
  // RooFitResult *results_HS       = (RooFitResult*)file_RFR_HS->Get("nll_myFit_myTrees");
  RooFitResult *results_HS       = (RooFitResult*)file_RFR_HS->Get("nll_myFit_myTrees");
  RooRealVar* mean_fitresult_HS  = (RooRealVar*)( (results_HS->floatParsFinal()).find("bkg_Mass_mean") );
  RooRealVar* sigma_fitresult_HS = (RooRealVar*)( (results_HS->floatParsFinal()).find("bkg_Mass_sigma") );
  float mean_HS     = mean_fitresult_HS->getVal(); 
  float meanErr_HS  = mean_fitresult_HS->getError(); 
  float sigma_HS    = sigma_fitresult_HS->getVal(); 
  float sigmaErr_HS = sigma_fitresult_HS->getError(); 
  // cout << mean_HS  << " " << meanErr_HS  << endl;
  // cout << sigma_HS << " " << sigmaErr_HS << endl;

  cout << endl;
  cout << "Signal region" << endl;
  theFit.initialize("fitres/fitBackground_signalRegion.config");  
  thePdfS = theFit.getPdf("myFit");
  thePdfS->plotOn(plot, RooFit::LineColor(kRed));
  RooDataSet *genDataS = thePdfS->generate(setqui,2000000,kTRUE,kFALSE);
  cout << endl;
  cout << endl;
  cout << "parameters for the signal region fit: " << endl;  
  (thePdfS->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_SR = new TFile("fitres/fitRes_region2.root");
  // RooFitResult *results_SR       = (RooFitResult*)file_RFR_SR->Get("nll_myFit_myTrees");
  RooFitResult *results_SR       = (RooFitResult*)file_RFR_SR->Get("nll_myFit_myTrees");
  RooRealVar* mean_fitresult_SR  = (RooRealVar*)( (results_SR->floatParsFinal()).find("bkg_Mass_mean") );
  RooRealVar* sigma_fitresult_SR = (RooRealVar*)( (results_SR->floatParsFinal()).find("bkg_Mass_sigma") );
  float mean_SR     = mean_fitresult_SR->getVal(); 
  float meanErr_SR  = mean_fitresult_SR->getError(); 
  float sigma_SR    = sigma_fitresult_SR->getVal(); 
  float sigmaErr_SR = sigma_fitresult_SR->getError(); 
  // cout << mean_SR  << " " << meanErr_SR  << endl;
  // cout << sigma_SR << " " << sigmaErr_SR << endl;
  cout << endl;
  cout << endl;

  // plot from the original pdfs
  TCanvas *myC = new TCanvas("myC","",1);
  myC->cd();
  plot->SetYTitle("Events");
  plot->Draw();
  myC->SaveAs("fitres/mGGJJ_Background_allFits.png");  

  // Trees from the previous toys
  TTree *treeGenDataL  = dataset2tree(genDataL);
  TH1F *h1_mggjj_genL;
  if(opts.getBoolVal("lowMass"))
    h1_mggjj_genL = new TH1F("h1_mggjj_genL","h1_mggjj_genL",50,200.,700.);
  else 
    h1_mggjj_genL = new TH1F("h1_mggjj_genL","h1_mggjj_genL",60,300.,1000.);    
  h1_mggjj_genL->Sumw2();
  treeGenDataL->Project("h1_mggjj_genL","mggjj");

  TTree *treeGenDataH = dataset2tree(genDataH);
  TH1F *h1_mggjj_genH;
  if(opts.getBoolVal("lowMass"))
    h1_mggjj_genH = new TH1F("h1_mggjj_genH","h1_mggjj_genH",50,200.,700.);
  else 
    h1_mggjj_genH = new TH1F("h1_mggjj_genH","h1_mggjj_genH",60,300.,1000.);    
  h1_mggjj_genH->Sumw2();
  treeGenDataH->Project("h1_mggjj_genH","mggjj");

  TTree *treeGenDataS = dataset2tree(genDataS);
  TH1F *h1_mggjj_genS;
  if(opts.getBoolVal("lowMass"))
    h1_mggjj_genS = new TH1F("h1_mggjj_genS","h1_mggjj_genS",50,200.,700.);
  else 
    h1_mggjj_genS = new TH1F("h1_mggjj_genS","h1_mggjj_genS",60,300.,1000.);    
  h1_mggjj_genS->Sumw2();
  treeGenDataS->Project("h1_mggjj_genS","mggjj");


  // plot from the generated datasets
  h1_mggjj_genL->SetLineColor(kBlue);
  h1_mggjj_genH->SetLineColor(kGreen);
  h1_mggjj_genS->SetLineColor(kRed);

  h1_mggjj_genL->Scale(1./(h1_mggjj_genL->Integral()));
  h1_mggjj_genH->Scale(1./(h1_mggjj_genH->Integral()));
  h1_mggjj_genS->Scale(1./(h1_mggjj_genS->Integral()));

  h1_mggjj_genL->Draw("hist");
  h1_mggjj_genH->Draw("samehist");
  h1_mggjj_genS->Draw("samehist");
  myC->SaveAs("fitres/afterGeneration.png");  


  // now ratio of the histos from toys
  TH1F *h1_mggjj_alphaFromL = h1_mggjj_genS->Clone("h1_mggjj_alphaFromL");                                                 
  h1_mggjj_alphaFromL->Divide(h1_mggjj_genL);                                                                                
  h1_mggjj_alphaFromL->GetXaxis()->SetTitle("alpha (from low)"); 
  h1_mggjj_alphaFromL->DrawNormalized("hist");
  h1_mggjj_alphaFromL->SetLineColor(kBlue);
  myC->SaveAs("fitres/alphaFromLowSideband.png");

  TH1F *h1_mggjj_alphaFromH = h1_mggjj_genS->Clone("h1_mggjj_alphaFromH");                                                 
  h1_mggjj_alphaFromH->Divide(h1_mggjj_genH);                                                                                
  h1_mggjj_alphaFromH->GetXaxis()->SetTitle("alpha (from high)"); 
  h1_mggjj_alphaFromH->SetLineColor(kGreen);
  h1_mggjj_alphaFromH->DrawNormalized("hist");
  myC->SaveAs("fitres/alphaFromHighSideband.png");
  
  // saving the histos
  TFile *myOutFile = new TFile("myOutFile.root","RECREATE");
  plot->Write();
  h1_mggjj_genL->Write();
  h1_mggjj_genH->Write();
  h1_mggjj_genS->Write();
  h1_mggjj_alphaFromL->Write();
  h1_mggjj_alphaFromH->Write();


  // summary of ratios between parameters 
  float ratioMean_LSoSR    = mean_LS/mean_SR;
  float errMLSoMLS         = meanErr_LS/mean_LS;
  float errMSRoMSR         = meanErr_SR/mean_SR;
  float errRatioMean_LSoSR = ratioMean_LSoSR*sqrt(errMLSoMLS*errMLSoMLS + errMSRoMSR*errMSRoMSR); 
  // 
  float ratioSigma_LSoSR    = sigma_LS/sigma_SR;
  float errSLSoSLS          = sigmaErr_LS/sigma_LS;
  float errSSRoSSR          = sigmaErr_SR/sigma_SR;
  float errRatioSigma_LSoSR = ratioSigma_LSoSR*sqrt(errSLSoSLS*errSLSoSLS + errSSRoSSR*errSSRoSSR); 
  cout << endl;
  cout << "my LS/SR ratios: mean  = " << ratioMean_LSoSR  << " +/- " << errRatioMean_LSoSR  << endl;
  cout << "my LS/SR ratios: sigma = " << ratioSigma_LSoSR << " +/- " << errRatioSigma_LSoSR << endl;
  cout << endl;  
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Make the plot for a given variable
RooPlot *MakePlot(TString VarName, MLFit* theFit, RooDataSet* theData, int nbins, bool poissonError=true)
{
  return plot;
}

TTree *dataset2tree(RooDataSet *dataset){

  const RooArgSet *args = dataset->get();
  RooArgList argList(*args);

  Double_t variables[50];
  Long64_t nEntries= dataset->numEntries();

  TTree *tree = new TTree("tree","tree");
  tree->SetDirectory(0);
  TIterator *it1=NULL;
  it1 = argList.createIterator();
  int index1=0;
  for(RooRealVar *var = (RooRealVar *) it1->Next(); var!=NULL;
      var = (RooRealVar *) it1->Next(),index1++){
    TString name(var->GetName());
    name.ReplaceAll("-","_");
    tree->Branch(name, &(variables[index1]), name+"/D");
  }

  for(Long64_t jentry=0; jentry<nEntries; jentry++){

    TIterator *it=NULL;
    RooArgList argList1(*(dataset->get(jentry)));
    it = argList1.createIterator();

    int index=0;
    for(RooRealVar *var = (RooRealVar *) it->Next(); var!=NULL;
        var = (RooRealVar *) it->Next(), index++){
      variables[index]=var->getVal();
    }

    delete it;
    tree->Fill();
  }
  tree->ResetBranchAddresses();

  return tree;
}
