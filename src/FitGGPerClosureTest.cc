
MLOptions GetDefaultOptions() {
  MLOptions opts;
  opts.addBoolOption("lowMass",  "Fit low mass region",  kTRUE);

  return opts;
}

// declarations
RooDataSet *getDataSet(const char *rootfile, const char *treename, bool weightedDataset);
RooDataSet *getDataSet2(const char *rootfile, const char *treename, int category);
void FitGGPerAlphaMC(int region, int category);   
void FitGGPerAlphaData(int region, int category);   
void PlotGGPerAlphaMC(int region, int category, int nbins);     
void PlotGGPerAlphaData(int region, int category, int nbins);   
void PlotGGPerAlpha_closure_lowMass(int category);    
void PlotGGPerAlpha_closure_highMass(int category);    

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
  */

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

  /*
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
  */

  /*
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
  */

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

  /*
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
  */

  cout << endl;
  cout << endl;

  cout << "Final closure checks" << endl;
  if(opts.getBoolVal("lowMass")) {
    // PlotGGPerAlpha_closure_lowMass(2);    
    PlotGGPerAlpha_closure_lowMass(1);    
    // PlotGGPerAlpha_closure_lowMass(0);
  }    
  else {
    // PlotGGPerAlpha_closure_highMass(2);     
    PlotGGPerAlpha_closure_highMass(1);      
    // PlotGGPerAlpha_closure_highMass(0);      
  }
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
  // sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_DiPhoton_8TeV_default_CSV.root");  
  sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_theseBackgrounds.root");

  char datasetnameS[200];
  sprintf(datasetnameS, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_Radion_M-300_madgraph_default_CSV.root");
  // sprintf(datasetnameS, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_Radion_M-300_madgraph_default_CSV.root");

  char treename[100];
  sprintf(treename,"myTrees");   

  RooDataSet *data = getDataSet(datasetnameB,  treename, true);

  // selection 
  if(opts.getBoolVal("lowMass")) {

    if (category==2) {        // no btag category - chiara: qui metto i tagli mjj come per 1btag, che sono piu' loose
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");

    } else if (category==1) { // btag category == 1: 1 btagged jet
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");

    } else if (category==0) { // btag category == 0: 2 btagged jets. 
                              // chiara: i tagli erano 95/150, ma troppo poca statistica. Metto come per 1btag 
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
    }

  }  else {

    if (category==2) {        // no btag category
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");

    } else if (category==1) { // btag category == 1: 1 btagged jet
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");

    } else if (category==0) { // btag category == 0: 2 btagged jets
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
    }
  }

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");
  
  // Initialize the fit
  char fitconfig[200];
  if(opts.getBoolVal("lowMass")) {  
    if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_LS.config");     
    if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_HS.config");    
    if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_SR.config");    
  } else {
    if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_LS.config");    
    if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_HS.config");    
    if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_SR.config");    
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
				       RooFit::SumW2Error(kTRUE));  
  fitres->Print("V");

  if (category==2) {
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat2_mc_closure.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat2_mc_closure.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat2_mc_closure.config");  

  } else if (category==1) {
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat1_mc_closure.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat1_mc_closure.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat1_mc_closure.config");  

  } else if (category==0) {
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat0_mc_closure.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat0_mc_closure.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat0_mc_closure.config");  
  }

  TFile *fileOut;
  if (category==2) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat2_mc_closure.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat2_mc_closure.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat2_mc_closure.root","RECREATE");

  } else if (category==1) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat1_mc_closure.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat1_mc_closure.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat1_mc_closure.root","RECREATE");

  } else if (category==0) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat0_mc_closure.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat0_mc_closure.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat0_mc_closure.root","RECREATE");
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
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      
    } else if (category==1) {
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      
    } else if (category==0) {   
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
    }
  } else {

    if(category==2) {
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300"); 
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300"); 
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300"); 

    } else if (category==1) {
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1"); 
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1"); 
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1"); 

    } else if (category==0) {
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2"); 
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2"); 
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2"); 
    }
  }

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");
  
  // Initialize the fit
  char fitconfig[200];
  if(opts.getBoolVal("lowMass")) {  
    if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_LS.config");     
    if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_HS.config");    
    if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_SR.config");    
  } else {
    if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_LS.config");    
    if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_HS.config");    
    if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_SR.config");    
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
				       RooFit::SumW2Error(kTRUE));  
  fitres->Print("V");

  if (category==2) {
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat2_data_closure.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat2_data_closure.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat2_data_closure.config");  

  } else if (category==1) { 
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat1_data_closure.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat1_data_closure.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat1_data_closure.config");  

  } else if (category==0) {
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat0_data_closure.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat0_data_closure.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat0_data_closure.config");  
  }

  TFile *fileOut;
  if (category==2) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat2_data_closure.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat2_data_closure.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat2_data_closure.root","RECREATE");

  } else if (category==1) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat1_data_closure.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat1_data_closure.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat1_data_closure.root","RECREATE");

  } else if (category==0) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat0_data_closure.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat0_data_closure.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat0_data_closure.root","RECREATE");
  }

  fileOut->cd();
  fitres->Write();
  fileOut->Close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlotGGPerAlpha_closure_lowMass(int category) {    
  
  cout << "final check at low mass, category = " << category << endl;

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
  if (category==2) theFit.initialize("fitres/fitBackground_lowSideband_cat2_mc_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_mc_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_mc_closure.config");  
  thePdfLMc = theFit.getPdf("myFit");
  thePdfLMc->plotOn(plot, RooFit::LineColor(kBlue));
  (thePdfLMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_LSmc;
  if (category==2) file_RFR_LSmc = new TFile("fitres/fitRes_region0_cat2_mc_closure.root");
  if (category==1) file_RFR_LSmc = new TFile("fitres/fitRes_region0_cat1_mc_closure.root");
  if (category==0) file_RFR_LSmc = new TFile("fitres/fitRes_region0_cat0_mc_closure.root");
  RooFitResult *results_LSmc       = (RooFitResult*)file_RFR_LSmc->Get("nll_myFit_myTrees");
  RooRealVar* mean_fitresult_LSmc  = (RooRealVar*)( (results_LSmc->floatParsFinal()).find("bkg_Mass_mean") );
  RooRealVar* sigma_fitresult_LSmc = (RooRealVar*)( (results_LSmc->floatParsFinal()).find("bkg_Mass_sigma") );
  float mean_LSmc     = mean_fitresult_LSmc->getVal(); 
  float meanErr_LSmc  = mean_fitresult_LSmc->getError(); 
  float sigma_LSmc    = sigma_fitresult_LSmc->getVal(); 
  float sigmaErr_LSmc = sigma_fitresult_LSmc->getError(); 

  cout << endl;
  cout << "Reading results from high sideband fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_highSideband_cat2_mc_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_highSideband_cat1_mc_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_highSideband_cat0_mc_closure.config");  
  thePdfHMc = theFit.getPdf("myFit");
  thePdfHMc->plotOn(plot, RooFit::LineColor(kGreen));
  (thePdfHMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_HSmc;
  if (category==2) file_RFR_HSmc = new TFile("fitres/fitRes_region1_cat2_mc_closure.root");
  if (category==1) file_RFR_HSmc = new TFile("fitres/fitRes_region1_cat1_mc_closure.root");
  if (category==0) file_RFR_HSmc = new TFile("fitres/fitRes_region1_cat0_mc_closure.root");
  RooFitResult *results_HSmc       = (RooFitResult*)file_RFR_HSmc->Get("nll_myFit_myTrees");
  RooRealVar* mean_fitresult_HSmc  = (RooRealVar*)( (results_HSmc->floatParsFinal()).find("bkg_Mass_mean") );
  RooRealVar* sigma_fitresult_HSmc = (RooRealVar*)( (results_HSmc->floatParsFinal()).find("bkg_Mass_sigma") );
  float mean_HSmc     = mean_fitresult_HSmc->getVal(); 
  float meanErr_HSmc  = mean_fitresult_HSmc->getError(); 
  float sigma_HSmc    = sigma_fitresult_HSmc->getVal(); 
  float sigmaErr_HSmc = sigma_fitresult_HSmc->getError(); 

  cout << endl;
  cout << "Reading results from signal region fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_signalRegion_cat2_mc_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_signalRegion_cat1_mc_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_signalRegion_cat0_mc_closure.config");  
  thePdfSMc = theFit.getPdf("myFit");
  thePdfSMc->plotOn(plot, RooFit::LineColor(kRed));
  (thePdfSMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_SRmc;
  if(category==2) file_RFR_SRmc = new TFile("fitres/fitRes_region2_cat2_mc_closure.root");
  if(category==1) file_RFR_SRmc = new TFile("fitres/fitRes_region2_cat1_mc_closure.root");
  if(category==0) file_RFR_SRmc = new TFile("fitres/fitRes_region2_cat0_mc_closure.root");
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
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat2_closure.png");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat1_closure.png");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat0_closure.png");  

  cout << endl;
  cout << "Reading results from low sideband fit in Data" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_lowSideband_cat2_data_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_data_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_data_closure.config");  
  thePdfLData = theFit.getPdf("myFit");
  (thePdfLData->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_LSdata;
  if (category==2) file_RFR_LSdata = new TFile("fitres/fitRes_region0_cat2_data_closure.root"); 
  if (category==1) file_RFR_LSdata = new TFile("fitres/fitRes_region0_cat1_data_closure.root"); 
  if (category==0) file_RFR_LSdata = new TFile("fitres/fitRes_region0_cat0_data_closure.root"); 
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
  
  // Loading the data dataset (signal region for closure) to be plot and convert into a root tree
  char datasetnameB[200];
  sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_Data2012_default_CSV.root");   
  char treename[100];
  sprintf(treename,"myTrees");
  RooDataSet *data = getDataSet2(datasetnameB, treename, category);
  if (category==0)                 
    data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1) 
    data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2) 
    data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
  TTree *treeData = dataset2tree(data);

  // histo from data tree
  TH1F *h1_mggjj_data = new TH1F("h1_mggjj_data","h1_mggjj_data",25,200.,700.);
  h1_mggjj_data->Sumw2();
  treeData->Project("h1_mggjj_data","mggjj");

  // Now generating events according to the fix landau shape and converting to a root tree
  // For pulls: generate the number of events in data
  int numberOfGen = (int)(h1_mggjj_data->Integral());
  TDatime *now = new TDatime();
  int today    = now->GetDate();
  int clock    = now->GetTime();
  int seed     = today+clock+65539;
  RooRandom::randomGenerator()->SetSeed(seed);
  RooDataSet *genData = landau->generate(setqui,numberOfGen,kTRUE,kFALSE);
  TTree *treeGenData  = dataset2tree(genData);
  
  // making histo from the previous trees and compare
  TH1F *h1_mggjj_fit = new TH1F("h1_mggjj_fit","h1_mggjj_fit",25,200.,700.);
  h1_mggjj_fit->Sumw2();
  treeGenData->Project("h1_mggjj_fit","mggjj");

  // residuals
  TH1F *h1_mggjj_res = new TH1F("h1_mggjj_res","h1_mggjj_res",25,200.,700.);
  h1_mggjj_res->Sumw2();

  TH1F *h1_mggjj_res_dist = new TH1F("h1_mggjj_res_dist","h1_mggjj_res_dist",9,-4.5,4.5);
  h1_mggjj_res_dist->Sumw2();

  if (h1_mggjj_fit->GetNbinsX() != h1_mggjj_data->GetNbinsX()) cout << "problem" << endl;
  if (h1_mggjj_res->GetNbinsX() != h1_mggjj_data->GetNbinsX()) cout << "problem" << endl;
  for (int ii=1; ii<=h1_mggjj_fit->GetNbinsX(); ii++) {
    float res = 0;
    float fromFit     = (float)h1_mggjj_fit->GetBinContent(ii);
    float fromData    = (float)h1_mggjj_data->GetBinContent(ii);
    float errFromFit  = (float)h1_mggjj_fit->GetBinError(ii);
    if (h1_mggjj_fit->GetBinError(ii)>0) res = (fromFit - fromData)/errFromFit;
    h1_mggjj_res->SetBinContent(ii, res);
    h1_mggjj_res_dist->Fill(res);
  }

  h1_mggjj_res->GetYaxis()->SetTitle("pull");
  h1_mggjj_res->GetXaxis()->SetTitle("mggjj");
  h1_mggjj_res_dist->GetXaxis()->SetTitle("pull");

  // final plots
  h1_mggjj_fit  -> SetFillColor(kRed); h1_mggjj_fit ->SetLineColor(kRed);
  h1_mggjj_data -> SetMarkerStyle(20);
  float highFit  = h1_mggjj_fit->GetMaximum(); 
  float highData = h1_mggjj_data->GetMaximum(); 
  float highMax;
  if (highFit>highData) {
    h1_mggjj_fit -> SetMaximum((highFit+0.05));
    h1_mggjj_data-> SetMaximum((highFit+0.05));
  } else {
    h1_mggjj_fit  -> SetMaximum((highData+0.05));
    h1_mggjj_data -> SetMaximum((highData+0.05));
  }

  TCanvas *myC2 = new TCanvas("myC2","",1);
  h1_mggjj_fit->Draw("hist");   h1_mggjj_data->Draw("pEsame");
  if (category==2)      myC2->SaveAs("fitres/closure_cat2.png");
  else if (category==1) myC2->SaveAs("fitres/closure_cat1.png");
  else if (category==0) myC2->SaveAs("fitres/closure_cat0.png");

  TCanvas *myC2b = new TCanvas("myC2b","",1);
  h1_mggjj_fit->Draw("hist");   h1_mggjj_data->Draw("pEsame");
  myC2b->SetLogy();
  if (category==2)      myC2b->SaveAs("fitres/closureLog_cat2.png");
  else if (category==1) myC2b->SaveAs("fitres/closureLog_cat1.png");
  else if (category==0) myC2b->SaveAs("fitres/closureLog_cat0.png");
  
  // Gaussian fit to pull distribution
  int peakBin   = h1_mggjj_res_dist->GetMaximumBin();
  double h_norm = h1_mggjj_res_dist->GetMaximum();
  double h_rms  = h1_mggjj_res_dist->GetRMS();
  double h_peak = h1_mggjj_res_dist->GetBinCenter(peakBin);
  TF1 *gausa = new TF1 ("gausa","[0]*exp(-1*(x-[1])*(x-[1])/2/[2]/[2])",h_peak-10*h_rms,h_peak+10*h_rms);
  gausa ->SetParameters(h_norm,h_peak,h_rms);
  h1_mggjj_res_dist->Fit("gausa","","",h_peak-4*h_rms,h_peak+4*h_rms);
  double gausMean  = gausa->GetParameter(1);
  double gausSigma = fabs(gausa->GetParameter(2));
  double gausChi2  = gausa->GetChisquare()/gausa->GetNDF();

  TCanvas *myC3 = new TCanvas("myC3","",1);
  myC3->Divide(1,2);
  myC3->cd(1); h1_mggjj_res->SetMinimum(-4); h1_mggjj_res->SetMaximum(4); h1_mggjj_res->Draw("pE");  
  gStyle->SetOptFit(1111);
  myC3->cd(2); h1_mggjj_res_dist->Draw();
  if (category==2)      myC3->SaveAs("fitres/closurePulls_cat2.png");
  else if (category==1) myC3->SaveAs("fitres/closurePulls_cat1.png");
  else if (category==0) myC3->SaveAs("fitres/closurePulls_cat0.png");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlotGGPerAlpha_closure_highMass(int category) {    
  
  cout << "final check at high mass, category = " << category << endl;

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
  if (category==2) theFit.initialize("fitres/fitBackground_lowSideband_cat2_mc_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_mc_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_mc_closure.config");  
  thePdfLMc = theFit.getPdf("myFit");
  thePdfLMc->plotOn(plot, RooFit::LineColor(kBlue));
  (thePdfLMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_LSmc;
  if (category==2) file_RFR_LSmc = new TFile("fitres/fitRes_region0_cat2_mc_closure.root");
  if (category==1) file_RFR_LSmc = new TFile("fitres/fitRes_region0_cat1_mc_closure.root");
  if (category==0) file_RFR_LSmc = new TFile("fitres/fitRes_region0_cat0_mc_closure.root");
  RooFitResult *results_LSmc     = (RooFitResult*)file_RFR_LSmc->Get("nll_myFit_myTrees");
  RooRealVar* exp_fitresult_LSmc = (RooRealVar*)( (results_LSmc->floatParsFinal()).find("bkg_Mass_exp") );
  float exp_LSmc    = exp_fitresult_LSmc->getVal(); 
  float expErr_LSmc = exp_fitresult_LSmc->getError(); 

  cout << endl;
  cout << "Reading results from high sideband fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_highSideband_cat2_mc_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_highSideband_cat1_mc_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_highSideband_cat0_mc_closure.config");  
  thePdfHMc = theFit.getPdf("myFit");
  thePdfHMc->plotOn(plot, RooFit::LineColor(kGreen));
  (thePdfHMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_HSmc;
  if (category==2) file_RFR_HSmc = new TFile("fitres/fitRes_region1_cat2_mc_closure.root");
  if (category==1) file_RFR_HSmc = new TFile("fitres/fitRes_region1_cat1_mc_closure.root");
  if (category==0) file_RFR_HSmc = new TFile("fitres/fitRes_region1_cat0_mc_closure.root");
  RooFitResult *results_HSmc     = (RooFitResult*)file_RFR_HSmc->Get("nll_myFit_myTrees");
  RooRealVar* exp_fitresult_HSmc = (RooRealVar*)( (results_HSmc->floatParsFinal()).find("bkg_Mass_exp") );
  float exp_HSmc    = exp_fitresult_HSmc->getVal(); 
  float expErr_HSmc = exp_fitresult_HSmc->getError(); 

  cout << endl;
  cout << "Reading results from signal region fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_signalRegion_cat2_mc_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_signalRegion_cat1_mc_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_signalRegion_cat0_mc_closure.config");  
  thePdfSMc = theFit.getPdf("myFit");
  thePdfSMc->plotOn(plot, RooFit::LineColor(kRed));
  (thePdfSMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_SRmc;
  if(category==2) file_RFR_SRmc = new TFile("fitres/fitRes_region2_cat2_mc_closure.root");
  if(category==1) file_RFR_SRmc = new TFile("fitres/fitRes_region2_cat1_mc_closure.root");
  if(category==0) file_RFR_SRmc = new TFile("fitres/fitRes_region2_cat0_mc_closure.root");
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
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat2_closure.png");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat1_closure.png");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat0_closure.png");  

  cout << endl;
  cout << "Reading results from low sideband fit in Data" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_lowSideband_cat2_data_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_data_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_data_closure.config");  
  thePdfLData = theFit.getPdf("myFit");
  (thePdfLData->getParameters(setqui))->writeToStream(std::cout,kFALSE);
  TFile *file_RFR_LSdata;
  if (category==2) file_RFR_LSdata = new TFile("fitres/fitRes_region0_cat2_data_closure.root"); 
  if (category==1) file_RFR_LSdata = new TFile("fitres/fitRes_region0_cat1_data_closure.root"); 
  if (category==0) file_RFR_LSdata = new TFile("fitres/fitRes_region0_cat0_data_closure.root"); 
  RooFitResult *results_LSdata     = (RooFitResult*)file_RFR_LSdata->Get("nll_myFit_myTrees");  
  RooRealVar* exp_fitresult_LSdata = (RooRealVar*)( (results_LSdata->floatParsFinal()).find("bkg_Mass_exp") );
  float exp_LSdata    = exp_fitresult_LSdata->getVal(); 
  float expErr_LSdata = exp_fitresult_LSdata->getError(); 
  cout << endl;

  cout << endl;
  cout << endl;
  cout << "first summary:" << endl;
  cout << "Data, low sideband: exp = " << exp_LSdata << " +/- " << expErr_LSdata << endl; 
  cout << "MC, low sideband: exp = "   << exp_LSmc   << " +/- " << expErr_LSmc   << endl;
  cout << "MC, high sideband: exp = "  << exp_HSmc   << " +/- " << expErr_HSmc   << endl;
  cout << "MC, signal region: exp = "  << exp_SRmc   << " +/- " << expErr_SRmc   << endl;
  cout << endl;
  cout << endl;

  char nameToSave[300];

  // Now replacing the values from sideband fit with alpha-corrected ones
  // and preparing a new PDF to be saved in the workspace for the fit
  float myCorrExp = exp_LSdata*(exp_SRmc/exp_LSmc);
  cout << "exp after correction = " << myCorrExp << endl;

  float ePars[3]={myCorrExp, 0,2000};
  sprintf(nameToSave,"mggjj_bkg_exp_cat%d",category);
  RooRealVar exp(nameToSave, nameToSave, ePars[0], ePars[1], ePars[2]);
  exp.setConstant(kTRUE);
  
  sprintf(nameToSave,"MggjjBkg_cat%d",category);
  RooAbsPdf *exponential = new RooExponential(nameToSave, nameToSave, *mggjj, exp);
  sprintf(nameToSave,"mggjj_bkg_exp_cat%d",category);
  float myExpControllo = (exponential->getParameters(setqui))->getRealValue(nameToSave);
  cout << "for check - must be the same as above: " << myExpControllo << endl;
  cout << endl;
  
  // Now loading the data dataset (signal region for closure) to be plot and convert into a root tree
  char datasetnameB[200];
  sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_Data2012_default_CSV.root");   
  char treename[100];
  sprintf(treename,"myTrees");
  RooDataSet *data = getDataSet2(datasetnameB, treename, category);
  if (category==0)                 
    data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
  else if (category==1) 
    data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
  else if (category==2) 
    data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
  TTree *treeData = dataset2tree(data);

  // hisyo from data tree
  TH1F *h1_mggjj_data = new TH1F("h1_mggjj_data","h1_mggjj_data",35,300.,1000.);
  h1_mggjj_data->Sumw2();
  treeData->Project("h1_mggjj_data","mggjj");

  // Now generating events according to the fix exponential shape and converting to a root tree
  // For pulls: generate the number of events in data 
  int numberOfGen = (int)(h1_mggjj_data->Integral());
  TDatime *now = new TDatime();
  int today    = now->GetDate();
  int clock    = now->GetTime();
  int seed     = today+clock+65539;
  RooRandom::randomGenerator()->SetSeed(seed);
  RooDataSet *genData = exponential->generate(setqui,numberOfGen,kTRUE,kFALSE);
  TTree *treeGenData  = dataset2tree(genData);
  
  // making histo from the previous trees and compare
  TH1F *h1_mggjj_fit = new TH1F("h1_mggjj_fit","h1_mggjj_fit",35,300.,1000.);
  h1_mggjj_fit->Sumw2();
  treeGenData->Project("h1_mggjj_fit","mggjj");
  
  // residuals
  TH1F *h1_mggjj_res = new TH1F("h1_mggjj_res","h1_mggjj_res",35,300.,1000.);
  h1_mggjj_res->Sumw2();

  TH1F *h1_mggjj_res_dist = new TH1F("h1_mggjj_res_dist","h1_mggjj_res_dist",9,-4.5,4.5);
  h1_mggjj_res_dist->Sumw2();

  if (h1_mggjj_fit->GetNbinsX() != h1_mggjj_data->GetNbinsX()) cout << "problem" << endl;
  if (h1_mggjj_res->GetNbinsX() != h1_mggjj_data->GetNbinsX()) cout << "problem" << endl;
  for (int ii=1; ii<=h1_mggjj_fit->GetNbinsX(); ii++) {
    float res = 0;
    float fromFit     = (float)h1_mggjj_fit->GetBinContent(ii);
    float fromData    = (float)h1_mggjj_data->GetBinContent(ii);
    float errFromFit  = (float)h1_mggjj_fit->GetBinError(ii);
    if (h1_mggjj_fit->GetBinError(ii)>0) res = (fromFit - fromData)/errFromFit;
    h1_mggjj_res->SetBinContent(ii, res);
    h1_mggjj_res_dist->Fill(res);
  }

  h1_mggjj_res->GetYaxis()->SetTitle("pull");
  h1_mggjj_res->GetXaxis()->SetTitle("mggjj");
  h1_mggjj_res_dist->GetXaxis()->SetTitle("pull");

  // final plots
  h1_mggjj_fit  -> SetFillColor(kRed); h1_mggjj_fit ->SetLineColor(kRed);
  h1_mggjj_data -> SetMarkerStyle(20);
  float highFit  = h1_mggjj_fit->GetMaximum(); 
  float highData = h1_mggjj_data->GetMaximum(); 
  float highMax;
  if (highFit>highData) {
    h1_mggjj_fit -> SetMaximum((highFit+0.05));
    h1_mggjj_data-> SetMaximum((highFit+0.05));
  } else {
    h1_mggjj_fit  -> SetMaximum((highData+0.05));
    h1_mggjj_data -> SetMaximum((highData+0.05));
  }

  TCanvas *myC2 = new TCanvas("myC2","",1);
  h1_mggjj_fit->Draw("hist");   h1_mggjj_data->Draw("pEsame");
  if (category==2)      myC2->SaveAs("fitres/closure_cat2.png");
  else if (category==1) myC2->SaveAs("fitres/closure_cat1.png");
  else if (category==0) myC2->SaveAs("fitres/closure_cat0.png");

  TCanvas *myC2b = new TCanvas("myC2b","",1);
  h1_mggjj_fit->Draw("hist");   h1_mggjj_data->Draw("pEsame");
  myC2b->SetLogy();
  if (category==2)      myC2b->SaveAs("fitres/closureLog_cat2.png");
  else if (category==1) myC2b->SaveAs("fitres/closureLog_cat1.png");
  else if (category==0) myC2b->SaveAs("fitres/closureLog_cat0.png");

  // Gaussian fit to pull distribution
  int peakBin   = h1_mggjj_res_dist->GetMaximumBin();
  double h_norm = h1_mggjj_res_dist->GetMaximum();
  double h_rms  = h1_mggjj_res_dist->GetRMS();
  double h_peak = h1_mggjj_res_dist->GetBinCenter(peakBin);
  TF1 *gausa = new TF1 ("gausa","[0]*exp(-1*(x-[1])*(x-[1])/2/[2]/[2])",h_peak-10*h_rms,h_peak+10*h_rms);
  gausa ->SetParameters(h_norm,h_peak,h_rms);
  h1_mggjj_res_dist->Fit("gausa","","",h_peak-4*h_rms,h_peak+4*h_rms);
  double gausMean  = gausa->GetParameter(1);
  double gausSigma = fabs(gausa->GetParameter(2));
  double gausChi2  = gausa->GetChisquare()/gausa->GetNDF();

  TCanvas *myC3 = new TCanvas("myC3","",1);
  myC3->Divide(1,2);
  myC3->cd(1);  h1_mggjj_res->SetMinimum(-4); h1_mggjj_res->SetMaximum(4); h1_mggjj_res->Draw("pE");  
  gStyle->SetOptFit(1111);
  myC3->cd(2);  h1_mggjj_res_dist->Draw();
  if (category==2)      myC3->SaveAs("fitres/closurePulls_cat2.png");
  else if (category==1) myC3->SaveAs("fitres/closurePulls_cat1.png");
  else if (category==0) myC3->SaveAs("fitres/closurePulls_cat0.png");
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

//////////////////////////////////////////////////////////////////////////////////////////////////

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
  // sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_DiPhoton_8TeV_default_CSV.root");  
  sprintf(datasetnameB, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_theseBackgrounds.root");
  
  char datasetnameS[200];
  sprintf(datasetnameS, "../HHggbb/finalizedTrees_Radion_perSideband/Radion_Radion_M-300_madgraph_default_CSV.root");

  char treename[100];
  sprintf(treename,"myTrees");   

  RooDataSet *data = getDataSet(datasetnameB,  treename, true);

  // selection 
  if(opts.getBoolVal("lowMass")) {

    if (category==2) {        // no btag category 
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");

    } else if (category==1) { // btag category == 1: 1 btagged jet
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");

    } else if (category==0) { // btag category == 0: 2 btagged jets
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
    }

  }  else {

    if (category==2) {        // no btag category
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");

    } else if (category==1) { // btag category == 1: 1 btagged jet
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");

    } else if (category==0) { // btag category == 0: 2 btagged jets
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
    }
  }

  bool usePoissonError=false;

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");
  
  // Initialize the fit
  char fitconfig[200];
  if(opts.getBoolVal("lowMass")) {  
    if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_LS.config");     
    if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_HS.config");    
    if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_SR.config");    
  } else {
    if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_LS.config");    
    if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_HS.config");    
    if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_SR.config");    
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

  // plot background in the full range, but normalized to fitted ranges 
  TCanvas *c = new TCanvas("c","fitResult");
  thePdf->plotOn(plot, RooFit::LineColor(kBlack));                                                                                                     
  plot->SetYTitle("Events");
  plot->Draw();

  char plotfilename[200];
  if (category==2) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_closure_cat2.png");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_closure_cat2.png");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_closure_cat2.png");     

  } else if (category==1) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_closure_cat1.png");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_closure_cat1.png");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_closure_cat1.png");     

  } else if (category==0) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_closure_cat0.png");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_closure_cat0.png");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_closure_cat0.png");     
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
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");

    } else if (category==1) { // btag category == 1: 1 btagged jet
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");

    } else if (category==0) { // btag category == 0: 2 btagged jets         
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
    }

  }  else {

    if (category==2) {        // no btag category
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");

    } else if (category==1) { // btag category == 1: 1 btagged jet
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");

    } else if (category==0) { // btag category == 0: 2 btagged jets
      if (region==0)      data = (RooDataSet*)data->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
      else if (region==1) data = (RooDataSet*)data->reduce("massggnewvtx>130 && massggnewvtx<=180 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
      else if (region==2) data = (RooDataSet*)data->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
    }
  }

  bool usePoissonError=true; 

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");
  
  // Initialize the fit
  char fitconfig[200];
  if(opts.getBoolVal("lowMass")) {  
    if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_LS.config");     
    if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_HS.config");    
    if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_SR.config");    
  } else {
    if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_LS.config");    
    if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_HS.config");    
    if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_SR.config");    
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
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_closure_cat2.png");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_closure_cat2.png");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_closure_cat2.png");     

  } else if (category==1) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_closure_cat1.png");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_closure_cat1.png");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_closure_cat1.png");     

  } else if (category==0) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_closure_cat0.png");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_closure_cat0.png");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_closure_cat0.png");     
  }
  c->SaveAs(plotfilename);
}
