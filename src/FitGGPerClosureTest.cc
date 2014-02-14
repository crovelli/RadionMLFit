
MLOptions GetDefaultOptions() {
  MLOptions opts;
  opts.addBoolOption("lowMass",  "Fit low mass region",  kTRUE);
  opts.addBoolOption("kinfit",   "Use a kinematic fit",  kTRUE);

  return opts;
}

// declarations
RooDataSet *getDataSet(const char *rootfile, const char *treename, bool weightedDataset);
RooDataSet *getDataSet2(const char *rootfile, const char *treename, int category);
RooDataSet *getDataSetCS(const char *rootfile, const char *treename);

// questi sono ok
void FitGGPerAlphaMC(int region, int category);   
void FitGGPerAlphaData(int region, int category);   

void PlotGGPerAlphaMC(int region, int category, int nbins);     
void PlotGGPerAlphaData(int region, int category, int nbins);   

void PlotGGPerAlpha_closure_lowMass_meth2(int category);    

// not to be used: CS files not up-to-date (but code is ok)
void FitGGPerAlphaCS(int region, int category);                
void PlotGGPerAlphaCS(int region, int category, int nbins);    
void PlotGGPerAlpha_closure_lowMass_meth2FromCS(int category);    

// not to be used: still to be updated to be consistent with the low mass one
void PlotGGPerAlpha_closure_highMass_meth2(int category);    



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

  // -----------------------------------------------------------------

  /*
  cout << "Fit to data: low sideband - no categorization"  << endl; 
  FitGGPerAlphaData(0,2);
  cout << "Fit to data: high sideband - no categorization" << endl; 
  FitGGPerAlphaData(1,2);
  cout << "Fit to data: signal region - no categorization" << endl; 
  FitGGPerAlphaData(2,2);
  cout << endl;

  cout << "Check fit to data: low sideband - no categorization"  << endl; 
  PlotGGPerAlphaData(0,2,25);
  cout << "Check fit to data: high sideband - no categorization" << endl; 
  PlotGGPerAlphaData(1,2,25);
  cout << "Check fit to data: signal region - no categorization" << endl; 
  PlotGGPerAlphaData(2,2,25);
  cout << endl;
  */

  /*
  cout << "Fit to data: low sideband - btag category=1"  << endl; 
  FitGGPerAlphaData(0,1);
  cout << "Fit to data: high sideband - btag category=1" << endl; 
  FitGGPerAlphaData(1,1);
  cout << "Fit to data: signal region - btag category=1" << endl; 
  FitGGPerAlphaData(2,1);
  cout << endl;

  cout << "Check fit to data: low sideband - btag category=1"  << endl; 
  PlotGGPerAlphaData(0,1,25);
  cout << "Check fit to data: high sideband - btag category=1" << endl; 
  PlotGGPerAlphaData(1,1,25);
  cout << "Check fit to data: signal region - btag category=1" << endl; 
  PlotGGPerAlphaData(2,1,25);
  cout << endl;
  */

  /* chiara: questo non va usato
  cout << "Fit to data: low sideband - btag category=2"  << endl; 
  FitGGPerAlphaData(0,0);
  cout << "Fit to data: high sideband - btag category=2" << endl; 
  FitGGPerAlphaData(1,0);
  cout << "Fit to data: signal region - btag category=2" << endl; 
  FitGGPerAlphaData(2,0);
  cout << endl;

  cout << "Check fit to data: low sideband - btag category=2"  << endl; 
  PlotGGPerAlphaData(0,0,25);
  cout << "Check fit to data: high sideband - btag category=2" << endl; 
  PlotGGPerAlphaData(1,0,25);
  cout << "Check fit to data: signal region - btag category=2" << endl; 
  PlotGGPerAlphaData(2,0,25);
  cout << endl;
  */


  // -----------------------------------------------------------------
  /*
  cout << "Fit to mc: low sideband - no categorization"  << endl; 
  FitGGPerAlphaMC(0,2);
   cout << "Fit to mc: high sideband - no categorization" << endl; 
  FitGGPerAlphaMC(1,2);
  cout << "Fit to mc: signal region - no categorization" << endl; 
  FitGGPerAlphaMC(2,2);
  cout << endl;

  cout << "Check fit to mc: low sideband - no categorization"  << endl; 
  PlotGGPerAlphaMC(0,2,25);
  cout << "Check fit to mc: high sideband - no categorization" << endl; 
  PlotGGPerAlphaMC(1,2,25);
  cout << "Check fit to mc: signal region - no categorization" << endl; 
  PlotGGPerAlphaMC(2,2,25);
  cout << endl;
  */

  /*
  cout << "Fit to mc: low sideband - btag category=1"  << endl; 
  FitGGPerAlphaMC(0,1);
  cout << "Fit to mc: high sideband - btag category=1" << endl; 
  FitGGPerAlphaMC(1,1);
  cout << "Fit to mc: signal region - btag category=1" << endl; 
  FitGGPerAlphaMC(2,1);
  cout << endl;

  cout << "Check fit to mc: low sideband - btag category=1"  << endl; 
  PlotGGPerAlphaMC(0,1,25);
  cout << "Check fit to mc: high sideband - btag category=1" << endl; 
  PlotGGPerAlphaMC(1,1,25);
  cout << "Check fit to mc: signal region - btag category=1" << endl; 
  PlotGGPerAlphaMC(2,1,25);
  cout << endl;
  */

  /* chiara: questo non va usato
  cout << "Fit to mc: low sideband - btag category=2"  << endl; 
  FitGGPerAlphaMC(0,0);
  cout << "Fit to mc: high sideband - btag category=2" << endl; 
  FitGGPerAlphaMC(1,0);
  cout << "Fit to mc: signal region - btag category=2" << endl; 
  FitGGPerAlphaMC(2,0);
  cout << endl;

  cout << "Check fit to mc: low sideband - btag category=2"  << endl; 
  PlotGGPerAlphaMC(0,0,25);
  cout << "Check fit to mc: high sideband - btag category=2" << endl; 
  PlotGGPerAlphaMC(1,0,25);
  cout << "Check fit to mc: signal region - btag category=2" << endl; 
  PlotGGPerAlphaMC(2,0,25);
  cout << endl;
  */


  // -----------------------------------------------------------------
  // da non accendere. I files non sono aggiornati
  /*
  cout << "Fit to data CS: low sideband - btag category=1"  << endl; 
  FitGGPerAlphaCS(0,1);
  cout << "Fit to data CS: high sideband - btag category=1" << endl; 
  FitGGPerAlphaCS(1,1);
  cout << "Fit to dataCS: signal region - btag category=1" << endl; 
  FitGGPerAlphaCS(2,1);
  cout << endl;

  cout << "Check fit to data CS: low sideband - btag category=1"  << endl; 
  PlotGGPerAlphaCS(0,1,25);
  cout << "Check fit to data CS: high sideband - btag category=1" << endl; 
  PlotGGPerAlphaCS(1,1,25);
  cout << "Check fit to data CS: signal region - btag category=1" << endl; 
  PlotGGPerAlphaCS(2,1,25);
  cout << endl;
  */

  cout << endl;
  cout << endl;

  cout << "Final closure checks" << endl;
  if(opts.getBoolVal("lowMass")) {
    PlotGGPerAlpha_closure_lowMass_meth2(1);    
    // PlotGGPerAlpha_closure_lowMass_meth2FromCS(1);    
    // PlotGGPerAlpha_closure_lowMass_meth2(0);
  }    
  else {
    // PlotGGPerAlpha_closure_highMass_meth2(1);      
    // PlotGGPerAlpha_closure_highMass_meth2(0);      
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
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma#gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 300., 1000.);
  
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

// preparing a roodataset from the CIC CS in data - the weight is different and is hardcoded
RooDataSet *getDataSetCS(const char *rootfile, const char *treename) {    
  
  cout << endl;
  cout << "running getDataSetCS" << endl;
  cout << endl;
  
  cout << "roofitting file " << rootfile << endl;   
  cout << "Creating a weighted dataset, where weight is pt_scaled_2D_weight_data." << endl;
  
  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // fit variables
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma#gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",       50., 250.);
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 300., 1000.);
  
  // needed bools
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory", 0.9,2.1);

  // weights
  RooRealVar* pt_scaled_2D_weight_data = new RooRealVar("pt_scaled_2D_weight_data", "pt_scaled_2D_weight_data", 0,10.);

  RooArgSet setall(*massggnewvtx,*mjj,*mggjj,*btagCategory,*pt_scaled_2D_weight_data);            

  cout << "rootfile is " << rootfile << endl;

  TFile *file = TFile::Open(rootfile);
  TTree *tree = (TTree*)file->Get(treename);

  RooDataSet *data = new RooDataSet("myTrees","dataset",tree,setall,0,pt_scaled_2D_weight_data->GetName());

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
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma#gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",       50., 250.);
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 300., 1000.);
  
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

  // w/wo kinematic fit
  if(opts.getBoolVal("kinfit")) 
    cout << "we're using a kinematic fit"     << endl;
  else 
    cout << "we're not using a kinematic fit" << endl;

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma#gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",       50., 250.);   
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 300., 1000.);
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
  char datasetnameB[700];
  if(!opts.getBoolVal("kinfit")) {
    sprintf(datasetnameB, "/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_senzaKF_senzaMassCuts/Radion_diphojet_sherpa_8TeV_default_CSV.root");
  } else {
    sprintf(datasetnameB, "/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_conKF_senzaMassCuts/Radion_diphojet_sherpa_8TeV_default_CSV.root");
  }

  char treename[300];
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

    } else if (category==0) { // btag category == 0: 2 btagged jets. 
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
    
    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closure_LS_mc.config");     
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closure_SR.config");    
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_LS.config");     
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_SR.config");    
    }

  } else {
    
    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closure_LS_mc.config");    
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closure_SR.config");    
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_LS.config");    
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_SR.config");    
    }
    
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
				       RooFit::SumW2Error(kFALSE));    // chiara: secondo me deve essere kfalse!
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

  // w/wo kinematic fit                                                                                                 
  if(opts.getBoolVal("kinfit"))
    cout << "we're using a kinematic fit"     << endl;
  else
    cout << "we're not using a kinematic fit" << endl;

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma#gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",       50., 250.);   
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 300., 1000.);
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
  char datasetnameB[700];
  if(!opts.getBoolVal("kinfit")) 
    sprintf(datasetnameB, "/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_senzaKF_senzaMassCuts/Radion_Data_default_CSV.root");
  else  
    sprintf(datasetnameB, "/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_conKF_senzaMassCuts/Radion_Data_default_CSV.root");
  
  char treename[300];
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

    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closure_LS.config");     
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closure_SR.config");    
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_LS.config");     
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_SR.config");    
      if (region==2 && category==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_SR_2btag.config"); 
    }
    
  } else {

    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closure_LS.config");    
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closure_SR.config");    
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_LS.config");    
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_SR.config");    
    }
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

// chiara: non aggiornati i files per versione finale senza regression e subleading gamma running pt cut
void FitGGPerAlphaCS(int region, int category) {    

  cout << "Fit to data in CIC CS. The region is " << region << ", the btag category is " << category << endl;

  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // w/wo kinematic fit                               
  if(opts.getBoolVal("kinfit"))
    cout << "we're using a kinematic fit"     << endl;
  else
    cout << "we're not using a kinematic fit" << endl;

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma#gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",       50., 250.);   
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 300., 1000.);
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
  char datasetnameB[700];
  if(!opts.getBoolVal("kinfit")) 
    sprintf(datasetnameB, "/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_senzaMassCuts__CS/Radion_Data_default_CSV__withWeightsForSidebands.root");    
  else
    sprintf(datasetnameB, "/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_conKinFit_senzaMassCuts__CS/Radion_Data_default_CSV__withWeightsForSidebands.root");    
  
  char treename[300];
  sprintf(treename,"myTrees_withWeight");   

  RooDataSet *data = getDataSetCS(datasetnameB, treename);

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

    if(!opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closureCS_LS.config");     
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closureCS_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closureCS_SR.config");    
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closureCS_LS.config");       
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closureCS_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closureCS_SR.config");    
    }

  } else {

    if(!opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closureCS_LS.config");    
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closureCS_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closureCS_SR.config");    
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closureCS_LS.config");  
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closureCS_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closureCS_SR.config");    
    } 
  }
  theFit.initialize(fitconfig);
  
  // Print Fit configuration 
  myPdf->getParameters(data)->selectByAttrib("Constant",kTRUE)->Print("V");  
  myPdf->getParameters(data)->selectByAttrib("Constant",kFALSE)->Print("V");

  // Fit to low/high sideband or signal region
  cout << endl;
  if (region==0)      cout << "Fit to data CS: Low sideband"  << endl;
  else if (region==1) cout << "Fit to data CS: High sideband" << endl;
  else if (region==2) cout << "Fit to data CS: Signal region" << endl;
  cout << endl;

  RooFitResult *fitres =  myPdf->fitTo(*data,
				       RooFit::ConditionalObservables(theFit.getNoNormVars("myFit")),
				       RooFit::FitOptions("MHTER"),
				       RooFit::NumCPU(4),
				       RooFit::SumW2Error(kTRUE));  
  fitres->Print("V");

  if (category==2) {
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat2_dataCS_closure.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat2_dataCS_closure.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat2_dataCS_closure.config");  

  } else if (category==1) { 
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat1_dataCS_closure.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat1_dataCS_closure.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat1_dataCS_closure.config");  

  } else if (category==0) {
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat0_dataCS_closure.config");  
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat0_dataCS_closure.config");  
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat0_dataCS_closure.config");  
  }

  TFile *fileOut;
  if (category==2) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat2_dataCS_closure.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat2_dataCS_closure.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat2_dataCS_closure.root","RECREATE");

  } else if (category==1) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat1_dataCS_closure.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat1_dataCS_closure.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat1_dataCS_closure.root","RECREATE");

  } else if (category==0) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat0_dataCS_closure.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat0_dataCS_closure.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat0_dataCS_closure.root","RECREATE");
  }

  fileOut->cd();
  fitres->Write();
  fileOut->Close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlotGGPerAlpha_closure_lowMass_meth2(int category) {    
  
  cout << "final check at low mass, method2, category = " << category << endl;

  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma#gamma} [GeV]",  100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);
  RooRealVar* mggjj        = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 200., 700.);   
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory",            -0.9, 2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(mggjj);
  theFit.AddFlatFileColumn(btagCategory);

  // define a fit model
  theFit.addModel("myFit", "HtoGG");
  theFit.addSpecies ("myFit", "bkg",  "Bkg Component");
  theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Landau", "bkg_Mass");      
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // for random generation
  TDatime *now = new TDatime();
  int today    = now->GetDate();
  int clock    = now->GetTime();
  int seed     = today+clock+65539;
  RooRandom::randomGenerator()->SetSeed(seed);

  // initializations for the plots
  TCanvas *c = new TCanvas("c","fitResult");
  RooRealVar* Var = theFit.RealObservable("mggjj");           
  double min      = Var->getMin();
  double max      = Var->getMax();
  RooPlot *plot   = Var->frame(min,max,25);
  RooPlot *plot2  = Var->frame(min,max,25);
  RooPlot *plot3  = Var->frame(min,max,25);
  RooPlot *plot4  = Var->frame(min,max,25);



  // Now reading the previous fit results for sidebands and signal region (data and mc).                                     
  // Generate events according to those distributions     
  RooAbsPdf *thePdfLMc, *thePdfSMc;
  RooAbsPdf *thePdfLData, *thePdfSData;
  RooArgSet setqui(*mggjj);
  
  cout << endl;
  cout << "Reading results from low sideband fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_lowSideband_cat2_mc_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_mc_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_mc_closure.config");  
  thePdfLMc = theFit.getPdf("myFit");
  thePdfLMc->plotOn(plot, RooFit::LineColor(kBlue));
  RooDataSet *genMcL = thePdfLMc->generate(setqui,2000000,kTRUE,kFALSE);
  (thePdfLMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);

  cout << endl;
  cout << "Reading results from signal region fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_signalRegion_cat2_mc_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_signalRegion_cat1_mc_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_signalRegion_cat0_mc_closure.config");  
  thePdfSMc = theFit.getPdf("myFit");
  thePdfSMc->plotOn(plot, RooFit::LineColor(kRed));
  RooDataSet *genMcS = thePdfSMc->generate(setqui,2000000,kTRUE,kFALSE);
  (thePdfSMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);

  cout << endl;
  cout << "Reading results from low sideband fit in Data" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_lowSideband_cat2_data_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_data_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_data_closure.config");  
  thePdfLData = theFit.getPdf("myFit");
  thePdfLData->plotOn(plot2, RooFit::LineColor(kBlue));
  RooDataSet *genDataL = thePdfLData->generate(setqui,2000000,kTRUE,kFALSE);
  (thePdfLData->getParameters(setqui))->writeToStream(std::cout,kFALSE);

  cout << endl;
  cout << "Reading results from signal region fit in Data" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_signalRegion_cat2_data_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_signalRegion_cat1_data_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_signalRegion_cat0_data_closure.config");  
  thePdfSData = theFit.getPdf("myFit");
  thePdfSData->plotOn(plot2, RooFit::LineColor(kRed));
  RooDataSet *genDataS = thePdfSData->generate(setqui,2000000,kTRUE,kFALSE);
  (thePdfSData->getParameters(setqui))->writeToStream(std::cout,kFALSE);


  // plot from the original pdfs from MC
  TH1F *myH_fuffaLR = new TH1F("myH_fuffaLR","myH_fuffaLR",100,0,100);
  TH1F *myH_fuffaSR = new TH1F("myH_fuffaSR","myH_fuffaSR",100,0,100);
  myH_fuffaLR->SetLineColor(kBlue);
  myH_fuffaSR->SetLineColor(kRed);
  myH_fuffaLR->SetLineWidth(2);
  myH_fuffaSR->SetLineWidth(2);

  TLegend *leg;
  leg = new TLegend(0.35,0.6,0.60,0.85);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.05);
  leg->SetFillColor(0);
  leg->AddEntry(myH_fuffaLR, "low m_{#gamma#gamma} sideband (mc)",  "l");
  leg->AddEntry(myH_fuffaSR, "m_{#gamma#gamma} signal region (mc)", "l");

  TLegend *leg2;
  leg2 = new TLegend(0.35,0.6,0.60,0.85);
  leg2->SetFillStyle(0);
  leg2->SetBorderSize(0);
  leg2->SetTextSize(0.05);
  leg2->SetFillColor(0);
  leg2->AddEntry(myH_fuffaLR, "low m_{#gamma#gamma} sideband (data)",  "l");
  leg2->AddEntry(myH_fuffaSR, "m_{#gamma#gamma} signal region (data)", "l");

  TCanvas *myC = new TCanvas("myC","",1);
  myC->cd();
  plot->SetYTitle("Events");
  plot->Draw();
  leg->Draw();
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat2_closure.png");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat1_closure.png");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat0_closure.png");  
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat2_closure.pdf");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat1_closure.pdf");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat0_closure.pdf");  

  plot2->SetYTitle("Events");
  plot2->Draw();
  leg2->Draw();
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat2_closure.png");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat1_closure.png");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat0_closure.png");  
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat2_closure.pdf");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat1_closure.pdf");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat0_closure.pdf");  


  // Trees and histos from the previous toys
  TTree *treeGenDataS = dataset2tree(genDataS);
  TTree *treeGenDataL = dataset2tree(genDataL);
  TTree *treeGenMcL   = dataset2tree(genMcL);
  TTree *treeGenMcS   = dataset2tree(genMcS);

  TH1F *h1_mggjj_genMcL, *h1_mggjj_genMcS, *h1_mggjj_genDataL, *h1_mggjj_genDataS;
  h1_mggjj_genMcL   = new TH1F("h1_mggjj_genMcL",  "h1_mggjj_genMcL",  50,200.,700.);
  h1_mggjj_genMcS   = new TH1F("h1_mggjj_genMcS",  "h1_mggjj_genMcS",  50,200.,700.);
  h1_mggjj_genDataL = new TH1F("h1_mggjj_genDataL","h1_mggjj_genDataL",50,200.,700.);
  h1_mggjj_genDataS = new TH1F("h1_mggjj_genDataS","h1_mggjj_genDataS",50,200.,700.);
  h1_mggjj_genMcL->Sumw2();
  h1_mggjj_genMcS->Sumw2();
  h1_mggjj_genDataL->Sumw2();
  h1_mggjj_genDataS->Sumw2();
  treeGenMcL  ->Project("h1_mggjj_genMcL",  "mggjj");
  treeGenMcS  ->Project("h1_mggjj_genMcS",  "mggjj");
  treeGenDataL->Project("h1_mggjj_genDataL","mggjj");
  treeGenDataS->Project("h1_mggjj_genDataS","mggjj");

  h1_mggjj_genMcL->SetLineColor(kBlue);
  h1_mggjj_genMcS->SetLineColor(kRed);
  h1_mggjj_genDataL->SetLineColor(kBlue);
  h1_mggjj_genDataS->SetLineColor(kRed);
  h1_mggjj_genDataS->SetMarkerColor(kRed);
  h1_mggjj_genMcL   -> Scale(1./(h1_mggjj_genMcL->Integral()));
  h1_mggjj_genMcS   -> Scale(1./(h1_mggjj_genMcS->Integral()));
  h1_mggjj_genDataL -> Scale(1./(h1_mggjj_genDataL->Integral()));
  h1_mggjj_genDataS -> Scale(1./(h1_mggjj_genDataS->Integral()));

  // to check wrt before
  h1_mggjj_genMcL->Draw("hist");
  h1_mggjj_genMcS->Draw("samehist");
  if (category==2) myC->SaveAs("fitres/mGGJJ_histosObtainedFromMcToys_cat2.png");
  else if (category==1) myC->SaveAs("fitres/mGGJJ_histosObtainedFromMcToys_cat1.png");
  else if (category==0) myC->SaveAs("fitres/mGGJJ_histosObtainedFromMcToys_cat0.png"); 

  h1_mggjj_genDataL->Draw("hist");
  h1_mggjj_genDataS->Draw("samehist");
  if (category==2) myC->SaveAs("fitres/mGGJJ_histosObtainedFromDataToys_cat2.png");
  else if (category==1) myC->SaveAs("fitres/mGGJJ_histosObtainedFromDataToys_cat1.png");
  else if (category==0) myC->SaveAs("fitres/mGGJJ_histosObh1_mggjj_genDataStainedFromDataToys_cat0.png"); 


  // -----------------------------------------------------------------------------------------------------------
  // Now making an histogram which is the product of previous ones and which should represent the data in the signal region
  // ==> this is our background estimate <==  
  TH1F *h1_resultHisto = new TH1F("h1_resultHisto", "h1_resultHisto", 50,200.,700.); 
  h1_resultHisto->Sumw2();
  h1_resultHisto->Add(h1_mggjj_genMcS,1);
  h1_resultHisto->Divide(h1_mggjj_genMcL);
  h1_resultHisto->Multiply(h1_mggjj_genDataL);
  h1_resultHisto->SetFillColor(kGreen-9);

  // also alpha histos may be useful                                                                                         
  TH1F *h1_alphaMc   = new TH1F("h1_alphaMc",   "h1_alphaMc",   50,200.,700.);
  TH1F *h1_alphaData = new TH1F("h1_alphaData", "h1_alphaData", 50,200.,700.);
  h1_alphaMc -> Sumw2();
  h1_alphaMc -> Add(h1_mggjj_genMcS,1);
  h1_alphaMc -> Divide(h1_mggjj_genMcL);
  h1_alphaData -> Sumw2();
  h1_alphaData -> Add(h1_mggjj_genDataS,1);
  h1_alphaData -> Divide(h1_mggjj_genDataL);
  h1_alphaMc   -> SetLineColor(6);
  h1_alphaData -> SetLineColor(4);
  h1_alphaMc   -> SetLineWidth(2);
  h1_alphaData -> SetLineWidth(2);
  h1_alphaMc   -> Rebin(2);
  h1_alphaData -> Rebin(2);

  

  // To check the closure:                                                                                                   
  //                                                                                                                         
  // We make a comparison between the estimate and the distribution from data in the signal region                           
  // To make it more sensitive, we normalize both histos (which are smooth being generated with 2M events)                   
  // to the number of events that we really have in data                                                                     
  // Also we scale the errors to the errors in the data histo (bin per bin)                                                  

  // Loading the data dataset (signal region for closure)                                                                    
  // to normalize back the rooDataHist before fitting and get sensitive errors
  RooDataSet *dataSigRegion;
  if(!opts.getBoolVal("kinfit")) 
    dataSigRegion = getDataSet2("/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_senzaKF_senzaMassCuts/Radion_Data_default_CSV.root", "myTrees", category);
  else
    dataSigRegion = getDataSet2("/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_conKF_senzaMassCuts/Radion_Data_default_CSV.root", "myTrees", category);

  if (category==0)
    dataSigRegion = (RooDataSet*)dataSigRegion->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1)
    dataSigRegion = (RooDataSet*)dataSigRegion->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2)
    dataSigRegion = (RooDataSet*)datasigRegion->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
  float numEntries = (float)(dataSigRegion->numEntries());

  // putting it into an histogram                                                                                            
  TTree *treeData = dataset2tree(dataSigRegion);
  TH1F *h1_mggjj_data = new TH1F("h1_mggjj_data","h1_mggjj_data",50,200.,700.);
  h1_mggjj_data->Sumw2();
  treeData->Project("h1_mggjj_data","mggjj");

  // proper normalization for estimate and toys from "real" data                                                             
  h1_resultHisto->Scale( numEntries / (h1_resultHisto->Integral()) );
  h1_mggjj_genDataS->Scale( numEntries / (h1_mggjj_genDataS->Integral()) );
  if (h1_resultHisto->GetNbinsX() != h1_mggjj_genDataS->GetNbinsX()) cout << "problem" << endl;
  if (h1_resultHisto->GetNbinsX() != h1_mggjj_data->GetNbinsX())     cout << "problem" << endl;

  for (int ii=1; ii<=h1_mggjj_data->GetNbinsX(); ii++) {
    float thisRealError = h1_mggjj_data->GetBinError(ii);
    h1_mggjj_genDataS->SetBinError(ii,thisRealError);
  }
  h1_mggjj_genDataS->SetMinimum(0);
  h1_resultHisto->SetMinimum(0);


  // plots to check                                                                                                          
  TLegend *leg3;
  leg3 = new TLegend(0.35,0.5,0.90,0.75);
  leg3->SetFillStyle(0);
  leg3->SetBorderSize(0);
  leg3->SetTextSize(0.05);
  leg3->SetFillColor(0);
  leg3->AddEntry(h1_resultHisto,    "estimated from sidebands", "f");
  leg3->AddEntry(h1_mggjj_genDataS, "data in signal region",    "p");

  TCanvas myC2a("myC2a","",1);
  myC2a.cd();
  h1_resultHisto->Draw("hist");
  if (category==2)      myC2a.SaveAs("fitres/resultHisto_cat2.png");
  else if (category==1) myC2a.SaveAs("fitres/resultHisto_cat1.png");
  else if (category==0) myC2a.SaveAs("fitres/resultHisto_cat0.png");

  TCanvas myC2b("myC2b","",1);
  myC2b.cd();
  h1_mggjj_genDataS->Draw("pE");
  h1_resultHisto   ->Draw("samehist");
  h1_mggjj_genDataS->Draw("samepE");
  leg3->Draw();
  if (category==2)      myC2b.SaveAs("fitres/resultHistoCheck_cat2.png");
  else if (category==1) myC2b.SaveAs("fitres/resultHistoCheck_cat1.png");
  else if (category==0) myC2b.SaveAs("fitres/resultHistoCheck_cat0.png");
  if (category==2)      myC2b.SaveAs("fitres/resultHistoCheck_cat2.pdf");
  else if (category==1) myC2b.SaveAs("fitres/resultHistoCheck_cat1.pdf");
  else if (category==0) myC2b.SaveAs("fitres/resultHistoCheck_cat0.pdf");

  // plots to check alpha                                                                                                    
  TLegend *leg4;
  leg4 = new TLegend(0.5,0.5,0.75,0.75);
  leg4->SetFillStyle(0);
  leg4->SetBorderSize(0);
  leg4->SetTextSize(0.05);
  leg4->SetFillColor(0);
  leg4->AddEntry(h1_alphaMc,   "#alpha from MC",  "l");
  leg4->AddEntry(h1_alphaData, "#alpha from data", "l");

  TCanvas myC2c("myC2c","",1);
  myC2c.cd();
  h1_alphaMc->DrawNormalized("hist");
  h1_alphaData->DrawNormalized("samehist");
  leg4->Draw();
  if (category==2)      myC2c.SaveAs("fitres/alpha_cat2.png");
  else if (category==1) myC2c.SaveAs("fitres/alpha_cat1.png");
  else if (category==0) myC2c.SaveAs("fitres/alpha_cat0.png");
  if (category==2)      myC2c.SaveAs("fitres/alpha_cat2.pdf");
  else if (category==1) myC2c.SaveAs("fitres/alpha_cat1.pdf");
  else if (category==0) myC2c.SaveAs("fitres/alpha_cat0.pdf");

  // useful root file
  TFile *myResultFile;
  if (category==2)      myResultFile = new TFile("fitres/myResultFile_cat2.root","RECREATE");
  else if (category==1) myResultFile = new TFile("fitres/myResultFile_cat1.root","RECREATE");
  else if (category==0) myResultFile = new TFile("fitres/myResultFile_cat0.root","RECREATE");
  myResultFile->cd();
  h1_resultHisto->Write();
  myResultFile->Close();


  // -----------------------------------------------------------------------                                                 
  // Now we fit the final distribution to get the PDF for the analysis      

  // Roodatahist of this histogram to fit with a landau
  RooRealVar meanL1("meanL1",   "meanL1", 300, 200., 400.);
  RooRealVar sigmaL1("sigmaL1", "sigmaL1", 40,  20.,  60.);
  RooLandau landau1("landau1",  "landau1", *mggjj, meanL1, sigmaL1);

  RooDataHist resultHistoRDH("resultHistoRDH", "resultHistoRDH", *mggjj, h1_resultHisto);
  landau1.fitTo(resultHistoRDH, RooFit::SumW2Error(kFALSE));    // chiara: secondo me deve essere kfalse!);
  resultHistoRDH.plotOn(plot3, RooFit::LineColor(kBlack));
  landau1.plotOn(plot3, RooFit::LineColor(kGreen));

  cout << endl;
  cout << "--------------------------------------------------------"    << endl;
  cout << "getting the fit result before renormalization"               << endl;
  cout << "mean: "  << meanL1.getVal()  << " +- " << meanL1.getError()  << endl;
  cout << "sigma: " << sigmaL1.getVal() << " +- " << sigmaL1.getError() << endl;
  cout << "--------------------------------------------------------"    << endl;

  TCanvas myC2("myC2","",1);
  myC2.cd();
  plot3->SetYTitle("Events");
  plot3->Draw();
  if      (category==2) myC2.SaveAs("fitres/resultHistoWithFit_cat2.png");
  else if (category==1) myC2.SaveAs("fitres/resultHistoWithFit_cat1.png");
  else if (category==0) myC2.SaveAs("fitres/resultHistoWithFit_cat0.png");



  // this is done with very small errors, because they come from 2M events for each histo                                    
  // First we rescale the errors of the histos used to make the final one to be representative                               
  // of the initial statistics, then we re-do the fit                                                                        

  // loading the dataset for data in low sideband                                                                            
  RooDataSet *dataL;
  if(!opts.getBoolVal("kinfit")) 
    dataL = getDataSet2("/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_senzaKF_senzaMassCuts/Radion_Data_default_CSV.root", "myTrees", category);
  else
    dataL = getDataSet2("/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_conKF_senzaMassCuts/Radion_Data_default_CSV.root", "myTrees", category);

  if (category==0)
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1)
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2)
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");


  // loading the dataset for MC in low sideband                                                                              
  RooDataSet *mcL;
  if(!opts.getBoolVal("kinfit")) 
    mcL = getDataSet("/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_senzaKF_senzaMassCuts/Radion_diphojet_sherpa_8TeV_default_CSV.root", "myTrees", true);
  else
    mcL = getDataSet("/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_conKF_senzaMassCuts/Radion_diphojet_sherpa_8TeV_default_CSV.root", "myTrees", true);

  if (category==0)
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1)
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2)
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");

  
  // loading the dataset for MC in the signal region                                                                         
  RooDataSet *mcS;
  if(!opts.getBoolVal("kinfit")) 
    mcS = getDataSet("/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_senzaKF_senzaMassCuts/Radion_diphojet_sherpa_8TeV_default_CSV.root", "myTrees", true);
  else 
    mcS = getDataSet("/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_conKF_senzaMassCuts/Radion_diphojet_sherpa_8TeV_default_CSV.root", "myTrees", true);

  if (category==0)
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1)
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2)
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");


  // putting them all into histograms                                                                                        
  TTree *treeDataL = dataset2tree(dataL);
  TTree *treeMcL   = dataset2tree(mcL);
  TTree *treeMcS   = dataset2tree(mcS);

  TH1F *h1_dataL = new TH1F("h1_dataL","h1_dataL",50,200.,700.);
  TH1F *h1_mcL   = new TH1F("h1_mcL",  "h1_mcL",  50,200.,700.);
  TH1F *h1_mcS   = new TH1F("h1_mcS",  "h1_mcS",  50,200.,700.);
  h1_dataL  -> Sumw2();
  h1_mcL    -> Sumw2();
  h1_mcS    -> Sumw2();
  treeDataL -> Project("h1_dataL","mggjj");
  treeMcL   -> Project("h1_mcL","mggjj");
  treeMcS   -> Project("h1_mcS","mggjj");
  

  // now cloning previous histos to replace the errors                                                                       
  TH1F *h1c_resultHisto    = new TH1F("h1c_resultHisto","h1c_resultHisto",50,200.,700.);
  TH1F *h1c_mggjj_genMcS   = (TH1F*)h1_mggjj_genMcS->Clone("h1c_mggjj_genMcS");
  TH1F *h1c_mggjj_genMcL   = (TH1F*)h1_mggjj_genMcL->Clone("h1c_mggjj_genMcL");
  TH1F *h1c_mggjj_genDataL = (TH1F*)h1_mggjj_genDataL->Clone("h1c_mggjj_genDataL");
  h1c_resultHisto->Sumw2();

  for (int ii=1; ii<=h1c_resultHisto->GetNbinsX(); ii++) {
    float thisRealError=-999.;

    thisRealError = h1_mcS->GetBinError(ii);
    h1c_mggjj_genMcS->SetBinError(ii,thisRealError);

    thisRealError = h1_mcL->GetBinError(ii);
    h1c_mggjj_genMcL->SetBinError(ii,thisRealError);

    thisRealError = h1_dataL->GetBinError(ii);
    h1c_mggjj_genDataL->SetBinError(ii,thisRealError);
  }

  h1c_resultHisto->Add(h1c_mggjj_genMcS,1);
  h1c_resultHisto->Divide(h1c_mggjj_genMcL);
  h1c_resultHisto->Multiply(h1c_mggjj_genDataL);
  h1c_resultHisto->SetFillColor(kRed-9);


  // same checks as before, now with larger errors on the estimate                                                           
  h1c_resultHisto->Scale( numEntries / (h1c_resultHisto->Integral()) );
  h1c_resultHisto->SetMinimum(0);
  h1c_resultHisto->SetMarkerStyle(20);

  /*
  TCanvas myC3b("myC3b","",1);
  myC3b.cd();
  h1_mggjj_genDataS->Draw("pE");
  h1c_resultHisto  ->Draw("samepE");
  h1_mggjj_genDataS->Draw("samepE");
  if (category==2)      myC3b.SaveAs("fitres/resultHistoCheck_withLargerErrors_cat2.png");
  else if (category==1) myC3b.SaveAs("fitres/resultHistoCheck_withLargerErrors_cat1.png");
  else if (category==0) myC3b.SaveAs("fitres/resultHistoCheck_withLargerErrors_cat0.png");
  */


  // New fit after proper normalization   
  RooRealVar meanL("meanL",   "meanL", 300, 200., 400.);
  RooRealVar sigmaL("sigmaL", "sigmaL", 40,  20.,  60.);
  RooLandau landau("landau", "landau", *mggjj, meanL, sigmaL);

  RooDataHist resultHistoRDH2("resultHistoRDH2", "resultHistoRDH2", *mggjj, h1c_resultHisto);
  landau.fitTo(resultHistoRDH2, RooFit::SumW2Error(kFALSE));    // chiara: secondo me deve essere kfalse!);
  resultHistoRDH2.plotOn(plot4, RooFit::LineColor(kBlack));
  landau.plotOn(plot4, RooFit::LineColor(kGreen));

  cout << endl;
  cout << "--------------------------------------------------------"  << endl;
  cout << "getting the fit result after renormalization"              << endl;
  cout << "mean: "  << meanL.getVal()  << " +- " << meanL.getError()  << endl;
  cout << "sigma: " << sigmaL.getVal() << " +- " << sigmaL.getError() << endl;
  cout << "--------------------------------------------------------"  << endl;
  cout << endl;


  // Fix the variables to the fit results for the remaining part
  meanL.setConstant(kTRUE);
  sigmaL.setConstant(kTRUE);


  // Prepare PDFs with modified parameters to graphically quantify errors
  float meanUp  = meanL.getVal() + meanL.getError(); 
  float meanDw  = meanL.getVal() - meanL.getError(); 
  float sigmaUp = sigmaL.getVal() + sigmaL.getError(); 
  float sigmaDw = sigmaL.getVal() - sigmaL.getError(); 
  RooRealVar meanLup("meanLup",   " meanLup", meanUp, meanUp, meanUp);
  RooRealVar meanLdw("meanLdw",    "meanLdw", meanDw, meanDw, meanDw);
  RooRealVar sigmaLup("sigmaLup",  "sigmaup", sigmaUp, sigmaUp, sigmaUp);
  RooRealVar sigmaLdw("sigmaLdw",  "sigmadw", sigmaDw, sigmaDw, sigmaDw);
  RooLandau landauMup("landauMup", "landauMup", *mggjj, meanLup, sigmaL);
  RooLandau landauMdw("landauMdw", "landauMdw", *mggjj, meanLdw, sigmaL);
  RooLandau landauSup("landauSup", "landauSup", *mggjj, meanL,   sigmaLup);
  RooLandau landauSdw("landauSdw", "landauSdw", *mggjj, meanL,   sigmaLdw);

  // Generating many events according to the fix landau shape and converting to a root tree
  TH1F *h1_mggjj_fit_many  = new TH1F("h1_mggjj_fit_many","h1_mggjj_fit_many",50,200.,700.);
  h1_mggjj_fit_many->Sumw2();
  RooDataSet *genDataMany = landau.generate(setqui,2000000,kTRUE,kFALSE);
  TTree *treeGenDataMany  = dataset2tree(genDataMany);
  treeGenDataMany->Project("h1_mggjj_fit_many","mggjj");
  if (h1_mggjj_fit_many->GetNbinsX() != h1_mggjj_data->GetNbinsX()) cout << "problem" << endl;
  h1_mggjj_fit_many -> SetFillColor(kGreen-9);

  // Now the same according pdfs with errors
  TH1F *h1_mggjj_fit_manyMup = new TH1F("h1_mggjj_fit_manyMup","h1_mggjj_fit_manyMup",50,200.,700.);
  h1_mggjj_fit_manyMup->Sumw2();
  RooDataSet *genDataManyMup = landauMup.generate(setqui,2000000,kTRUE,kFALSE);
  TTree *treeGenDataManyMup  = dataset2tree(genDataManyMup);
  treeGenDataManyMup->Project("h1_mggjj_fit_manyMup","mggjj");

  TH1F *h1_mggjj_fit_manyMdw = new TH1F("h1_mggjj_fit_manyMdw","h1_mggjj_fit_manyMdw",50,200.,700.);
  h1_mggjj_fit_manyMdw->Sumw2();
  RooDataSet *genDataManyMdw = landauMdw.generate(setqui,2000000,kTRUE,kFALSE);
  TTree *treeGenDataManyMdw  = dataset2tree(genDataManyMdw);
  treeGenDataManyMdw->Project("h1_mggjj_fit_manyMdw","mggjj");

  TH1F *h1_mggjj_fit_manySup = new TH1F("h1_mggjj_fit_manySup","h1_mggjj_fit_manySup",50,200.,700.);
  h1_mggjj_fit_manySup->Sumw2();
  RooDataSet *genDataManySup = landauSup.generate(setqui,2000000,kTRUE,kFALSE);
  TTree *treeGenDataManySup  = dataset2tree(genDataManySup);
  treeGenDataManySup->Project("h1_mggjj_fit_manySup","mggjj");

  TH1F *h1_mggjj_fit_manySdw = new TH1F("h1_mggjj_fit_manySdw","h1_mggjj_fit_manySdw",50,200.,700.);
  h1_mggjj_fit_manySdw->Sumw2();
  RooDataSet *genDataManySdw = landauSdw.generate(setqui,2000000,kTRUE,kFALSE);
  TTree *treeGenDataManySdw  = dataset2tree(genDataManySdw);
  treeGenDataManySdw->Project("h1_mggjj_fit_manySdw","mggjj");

  h1_mggjj_fit_manySup->SetLineColor(1);
  h1_mggjj_fit_manySdw->SetLineColor(1);
  h1_mggjj_fit_manyMup->SetLineColor(1);
  h1_mggjj_fit_manyMdw->SetLineColor(1);
  h1_mggjj_fit_manySup->SetLineWidth(2);
  h1_mggjj_fit_manySdw->SetLineWidth(2);
  h1_mggjj_fit_manyMup->SetLineWidth(2);
  h1_mggjj_fit_manyMdw->SetLineWidth(2);

  // normalization to the number of events in data SR
  h1_mggjj_fit_many->Scale(numEntries/(h1_mggjj_fit_many->Integral()));
  h1_mggjj_fit_manyMup->Scale(numEntries/(h1_mggjj_fit_manyMup->Integral()));
  h1_mggjj_fit_manyMdw->Scale(numEntries/(h1_mggjj_fit_manyMdw->Integral()));
  h1_mggjj_fit_manySup->Scale(numEntries/(h1_mggjj_fit_manySup->Integral()));
  h1_mggjj_fit_manySdw->Scale(numEntries/(h1_mggjj_fit_manySdw->Integral()));

  // comparison plots between fit and the original dataset
  float highFit = h1_mggjj_fit_many->GetMaximum();
  if ( highFit<(h1_mggjj_genDataS->GetMaximum()) )    highFit = h1_mggjj_genDataS->GetMaximum();
  if ( highFit<(h1_mggjj_fit_manyMup->GetMaximum()) ) highFit = h1_mggjj_fit_manyMup->GetMaximum();
  if ( highFit<(h1_mggjj_fit_manyMdw->GetMaximum()) ) highFit = h1_mggjj_fit_manyMdw->GetMaximum();
  if ( highFit<(h1_mggjj_fit_manySup->GetMaximum()) ) highFit = h1_mggjj_fit_manySup->GetMaximum();
  if ( highFit<(h1_mggjj_fit_manySdw->GetMaximum()) ) highFit = h1_mggjj_fit_manySdw->GetMaximum();
  h1_mggjj_genDataS->SetMaximum((highFit+0.1));
  h1_mggjj_fit_many->SetMaximum((highFit+0.1));
  h1_mggjj_fit_manyMup->SetMaximum((highFit+0.1));
  h1_mggjj_fit_manyMdw->SetMaximum((highFit+0.1));
  h1_mggjj_fit_manySup->SetMaximum((highFit+0.1));
  h1_mggjj_fit_manySdw->SetMaximum((highFit+0.1));
  
  TLegend *leg3;
  leg3 = new TLegend(0.5,0.6,0.75,0.85);
  leg3->SetFillStyle(0);
  leg3->SetBorderSize(0);
  leg3->SetTextSize(0.05);
  leg3->SetFillColor(0);
  leg3->AddEntry(h1_mggjj_genDataS, "data", "p");
  leg3->AddEntry(h1_mggjj_fit_many, "from sidebands",  "f");
  leg3->AddEntry(h1_mggjj_fit_manySup, "from sidebands (syst)", "l");
 
  TCanvas *myC4b = new TCanvas("myC4b","",1);
  h1_mggjj_fit_many->Draw("hist");   
  h1_mggjj_genDataS->Draw("pEsame");
  h1_mggjj_fit_manySup->Draw("histsame");
  h1_mggjj_fit_manySdw->Draw("histsame");
  h1_mggjj_fit_manyMup->Draw("histsame");
  h1_mggjj_fit_manyMdw->Draw("histsame");
  leg3->Draw();
  if (category==2)      myC4b->SaveAs("fitres/closureManyToys_cat2.png");
  else if (category==1) myC4b->SaveAs("fitres/closureManyToys_cat1.png");
  else if (category==0) myC4b->SaveAs("fitres/closureManyToys_cat0.png");

  TCanvas *myC5b = new TCanvas("myC5b","",1);
  h1_mggjj_fit_many->Draw("hist");   
  h1_mggjj_genDataS->Draw("pEsame");
  h1_mggjj_fit_manySup->Draw("histsame");
  h1_mggjj_fit_manySdw->Draw("histsame");
  h1_mggjj_fit_manyMup->Draw("histsame");
  h1_mggjj_fit_manyMdw->Draw("histsame");
  h1_mggjj_fit_many->SetMinimum(0.0001);
  h1_mggjj_genDataS->SetMinimum(0.0001);
  h1_mggjj_fit_manySup->SetMinimum(0.0001);
  h1_mggjj_fit_manySdw->SetMinimum(0.0001);
  h1_mggjj_fit_manyMup->SetMinimum(0.0001);
  h1_mggjj_fit_manyMdw->SetMinimum(0.0001);
  myC5b->SetLogy(1);
  leg3->Draw();
  if (category==2)      myC5b->SaveAs("fitres/closureManyToysLog_cat2.png");
  else if (category==1) myC5b->SaveAs("fitres/closureManyToysLog_cat1.png");
  else if (category==0) myC5b->SaveAs("fitres/closureManyToysLog_cat0.png");
  myC5b->SetLogy(0);

  /*
  // residuals vs shape
  TH1F *h1_mggjj_res_many = new TH1F("h1_mggjj_res_many","h1_mggjj_res_many",25,200.,700.);
  h1_mggjj_res_many->Sumw2();

  TH1F *h1_mggjj_res_dist_many = new TH1F("h1_mggjj_res_dist_many","h1_mggjj_res_dist_many",9,-4.5,4.5);
  h1_mggjj_res_dist_many->Sumw2();

  if (h1_mggjj_res_many->GetNbinsX() != h1_mggjj_data->GetNbinsX()) cout << "problem" << endl;

  for (int ii=1; ii<=h1_mggjj_fit_many->GetNbinsX(); ii++) {
    float res = 0;
    float fromFit     = (float)h1_mggjj_fit_many->GetBinContent(ii);
    float fromData    = (float)h1_mggjj_data->GetBinContent(ii);
    float errFromData = (float)h1_mggjj_data->GetBinError(ii);
    if (errFromData>0) res = (fromFit - fromData)/errFromData;
    h1_mggjj_res_many->SetBinContent(ii, res);
    h1_mggjj_res_dist_many->Fill(res);
  }
  
  h1_mggjj_res_many->GetYaxis()->SetTitle("pull");
  h1_mggjj_res_many->GetXaxis()->SetTitle("mggjj");

  h1_mggjj_res_dist_many->GetXaxis()->SetTitle("pull");   

  TCanvas *myC5b = new TCanvas("myC5b","",1);
  h1_mggjj_res_many->SetMinimum(-4); 
  h1_mggjj_res_many->SetMaximum(4); 
  h1_mggjj_res_many->Draw("pE");  
  if (category==2)      myC5b->SaveAs("fitres/closurePullsTrendManyToys_cat2.png");
  else if (category==1) myC5b->SaveAs("fitres/closurePullsTrendManyToys_cat1.png");
  else if (category==0) myC5b->SaveAs("fitres/closurePullsTrendManyToys_cat0.png");
  
  // Gaussian fit to pull distribution
  int peakBin   = h1_mggjj_res_dist_many->GetMaximumBin();
  double h_norm = h1_mggjj_res_dist_many->GetMaximum();
  double h_rms  = h1_mggjj_res_dist_many->GetRMS();
  double h_peak = h1_mggjj_res_dist_many->GetBinCenter(peakBin);
  TF1 *gausa = new TF1 ("gausa","[0]*exp(-1*(x-[1])*(x-[1])/2/[2]/[2])",h_peak-10*h_rms,h_peak+10*h_rms);
  gausa ->SetParameters(h_norm,h_peak,h_rms);
  h1_mggjj_res_dist_many->Fit("gausa","","",h_peak-4*h_rms,h_peak+4*h_rms);
  double gausMean  = gausa->GetParameter(1);
  double gausSigma = fabs(gausa->GetParameter(2));
  double gausChi2  = gausa->GetChisquare()/gausa->GetNDF();

  TCanvas *myC6b = new TCanvas("myC6b","",1);
  h1_mggjj_res_dist_many->Draw();
  if (category==2)      myC6b->SaveAs("fitres/closurePullsDistManyToys_cat2.png");
  else if (category==1) myC6b->SaveAs("fitres/closurePullsDistManyToys_cat1.png");
  else if (category==0) myC6b->SaveAs("fitres/closurePullsDistManyToys_cat0.png");
  */
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////

// chiara: non aggiornati con i files finali senza regression e con subleading gamma running pT cut 
void PlotGGPerAlpha_closure_lowMass_meth2FromCS(int category) {    
  
  cout << "final check at low mass, method2, alpha from CS, category = " << category << endl;

  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma#gamma} [GeV]",  100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);
  RooRealVar* mggjj        = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 200., 700.);   
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory",            -0.9, 2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(mggjj);
  theFit.AddFlatFileColumn(btagCategory);

  // define a fit model
  theFit.addModel("myFit", "HtoGG");
  theFit.addSpecies ("myFit", "bkg",  "Bkg Component");
  theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Landau", "bkg_Mass");      
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // for random generation
  TDatime *now = new TDatime();
  int today    = now->GetDate();
  int clock    = now->GetTime();
  int seed     = today+clock+65539;
  RooRandom::randomGenerator()->SetSeed(seed);

  // initializations for the plots
  TCanvas *c = new TCanvas("c","fitResult");
  RooRealVar* Var = theFit.RealObservable("mggjj");           
  double min      = Var->getMin();
  double max      = Var->getMax();
  RooPlot *plot   = Var->frame(min,max,25);
  RooPlot *plot2  = Var->frame(min,max,25);
  RooPlot *plot3  = Var->frame(min,max,25);
  RooPlot *plot4  = Var->frame(min,max,25);



  // Now reading the previous fit results for sidebands and signal region (data and mc).                                     
  // Generate events according to those distributions     
  RooAbsPdf *thePdfLMc,   *thePdfSMc;
  RooAbsPdf *thePdfLData, *thePdfSData;   
  RooArgSet setqui(*mggjj);
  
  cout << endl;
  cout << "Reading results from low sideband fit to data CS" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_lowSideband_cat2_dataCS_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_dataCS_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_dataCS_closure.config");  
  thePdfLMc = theFit.getPdf("myFit");
  thePdfLMc->plotOn(plot, RooFit::LineColor(kBlue));
  RooDataSet *genMcL = thePdfLMc->generate(setqui,2000000,kTRUE,kFALSE);
  (thePdfLMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);

  cout << endl;
  cout << "Reading results from signal region fit to data CS" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_signalRegion_cat2_dataCS_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_signalRegion_cat1_dataCS_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_signalRegion_cat0_dataCS_closure.config");  
  thePdfSMc = theFit.getPdf("myFit");
  thePdfSMc->plotOn(plot, RooFit::LineColor(kRed));
  RooDataSet *genMcS = thePdfSMc->generate(setqui,2000000,kTRUE,kFALSE);
  (thePdfSMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);

  cout << endl;
  cout << "Reading results from low sideband fit in Data" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_lowSideband_cat2_data_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_data_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_data_closure.config");  
  thePdfLData = theFit.getPdf("myFit");
  thePdfLData->plotOn(plot2, RooFit::LineColor(kBlue));
  RooDataSet *genDataL = thePdfLData->generate(setqui,2000000,kTRUE,kFALSE);
  (thePdfLData->getParameters(setqui))->writeToStream(std::cout,kFALSE);

  cout << endl;
  cout << "Reading results from signal region fit in Data" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_signalRegion_cat2_data_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_signalRegion_cat1_data_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_signalRegion_cat0_data_closure.config");  
  thePdfSData = theFit.getPdf("myFit");
  thePdfSData->plotOn(plot2, RooFit::LineColor(kRed));
  RooDataSet *genDataS = thePdfSData->generate(setqui,2000000,kTRUE,kFALSE);
  (thePdfSData->getParameters(setqui))->writeToStream(std::cout,kFALSE);


  // plot from the original pdfs from data CS
  TH1F *myH_fuffaLR = new TH1F("myH_fuffaLR","myH_fuffaLR",100,0,100);
  TH1F *myH_fuffaSR = new TH1F("myH_fuffaSR","myH_fuffaSR",100,0,100);
  myH_fuffaLR->SetLineColor(kBlue);
  myH_fuffaSR->SetLineColor(kRed);
  myH_fuffaLR->SetLineWidth(2);
  myH_fuffaSR->SetLineWidth(2);

  TLegend *leg;
  leg = new TLegend(0.35,0.6,0.60,0.85);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.05);
  leg->SetFillColor(0);
  leg->AddEntry(myH_fuffaLR, "low m_{#gamma#gamma} sideband (dataCS)",  "l");
  leg->AddEntry(myH_fuffaSR, "m_{#gamma#gamma} signal region (dataCS)", "l");

  TLegend *leg2;
  leg2 = new TLegend(0.35,0.6,0.60,0.85);
  leg2->SetFillStyle(0);
  leg2->SetBorderSize(0);
  leg2->SetTextSize(0.05);
  leg2->SetFillColor(0);
  leg2->AddEntry(myH_fuffaLR, "low m_{#gamma#gamma} sideband (data)",  "l");
  leg2->AddEntry(myH_fuffaSR, "m_{#gamma#gamma} signal region (data)", "l");

  TCanvas *myC = new TCanvas("myC","",1);
  myC->cd();
  plot->SetYTitle("Events");
  plot->Draw();
  leg->Draw();
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToDataCS_cat2_closure.png");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToDataCS_cat1_closure.png");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToDataCS_cat0_closure.png");  
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToDataCS_cat2_closure.pdf");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToDataCS_cat1_closure.pdf");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToDataCS_cat0_closure.pdf");  

  plot2->SetYTitle("Events");
  plot2->Draw();
  leg2->Draw();
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat2_closure.png");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat1_closure.png");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat0_closure.png");  
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat2_closure.pdf");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat1_closure.pdf");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat0_closure.pdf");  


  // Trees and histos from the previous toys
  TTree *treeGenDataS = dataset2tree(genDataS);
  TTree *treeGenDataL = dataset2tree(genDataL);
  TTree *treeGenMcL   = dataset2tree(genMcL);
  TTree *treeGenMcS   = dataset2tree(genMcS);

  TH1F *h1_mggjj_genMcL, *h1_mggjj_genMcS, *h1_mggjj_genDataL, *h1_mggjj_genDataS;
  h1_mggjj_genMcL   = new TH1F("h1_mggjj_genMcL",  "h1_mggjj_genMcL",  50,200.,700.);
  h1_mggjj_genMcS   = new TH1F("h1_mggjj_genMcS",  "h1_mggjj_genMcS",  50,200.,700.);
  h1_mggjj_genDataL = new TH1F("h1_mggjj_genDataL","h1_mggjj_genDataL",50,200.,700.);
  h1_mggjj_genDataS = new TH1F("h1_mggjj_genDataS","h1_mggjj_genDataS",50,200.,700.);
  h1_mggjj_genMcL->Sumw2();
  h1_mggjj_genMcS->Sumw2();
  h1_mggjj_genDataL->Sumw2();
  h1_mggjj_genDataS->Sumw2();
  treeGenMcL  ->Project("h1_mggjj_genMcL",  "mggjj");
  treeGenMcS  ->Project("h1_mggjj_genMcS",  "mggjj");
  treeGenDataL->Project("h1_mggjj_genDataL","mggjj");
  treeGenDataS->Project("h1_mggjj_genDataS","mggjj");

  h1_mggjj_genMcL   -> SetLineColor(kBlue);
  h1_mggjj_genMcS   -> SetLineColor(kRed);
  h1_mggjj_genDataL -> SetLineColor(kBlue);
  h1_mggjj_genDataS -> SetLineColor(kRed);
  h1_mggjj_genDataS -> SetMarkerColor(kRed);
  h1_mggjj_genMcL   -> Scale(1./(h1_mggjj_genMcL->Integral()));
  h1_mggjj_genMcS   -> Scale(1./(h1_mggjj_genMcS->Integral()));
  h1_mggjj_genDataL -> Scale(1./(h1_mggjj_genDataL->Integral()));
  h1_mggjj_genDataS -> Scale(1./(h1_mggjj_genDataS->Integral()));

  // to check wrt before
  h1_mggjj_genMcL->Draw("hist");
  h1_mggjj_genMcS->Draw("samehist");
  if (category==2)      myC->SaveAs("fitres/mGGJJ_histosObtainedFromDataCSToys_cat2.png");
  else if (category==1) myC->SaveAs("fitres/mGGJJ_histosObtainedFromDataCSToys_cat1.png");
  else if (category==0) myC->SaveAs("fitres/mGGJJ_histosObtainedFromDataCSToys_cat0.png"); 

  h1_mggjj_genDataL->Draw("hist");
  h1_mggjj_genDataS->Draw("samehist");
  if (category==2)      myC->SaveAs("fitres/mGGJJ_histosObtainedFromDataToys_cat2.png");
  else if (category==1) myC->SaveAs("fitres/mGGJJ_histosObtainedFromDataToys_cat1.png");
  else if (category==0) myC->SaveAs("fitres/mGGJJ_histosObtainedFromDataToys_cat0.png"); 


  // -----------------------------------------------------------------------------------------------------------
  // Now making an histogram which is the product of previous ones and which should represent the data in the signal region
  // ==> this is our background estimate <==  
  TH1F *h1_resultHisto = new TH1F("h1_resultHisto", "h1_resultHisto", 50,200.,700.); 
  h1_resultHisto->Sumw2();
  h1_resultHisto->Add(h1_mggjj_genMcS,1);
  h1_resultHisto->Divide(h1_mggjj_genMcL);
  h1_resultHisto->Multiply(h1_mggjj_genDataL);
  h1_resultHisto->SetFillColor(kGreen-9);

  // also alpha histos may be useful                                                                                         
  TH1F *h1_alphaMc   = new TH1F("h1_alphaMc",   "h1_alphaMc",   50,200.,700.);
  TH1F *h1_alphaData = new TH1F("h1_alphaData", "h1_alphaData", 50,200.,700.);
  h1_alphaMc -> Sumw2();
  h1_alphaMc -> Add(h1_mggjj_genMcS,1);
  h1_alphaMc -> Divide(h1_mggjj_genMcL);
  h1_alphaData -> Sumw2();
  h1_alphaData -> Add(h1_mggjj_genDataS,1);
  h1_alphaData -> Divide(h1_mggjj_genDataL);
  h1_alphaMc   -> SetLineColor(6);
  h1_alphaData -> SetLineColor(4);
  h1_alphaMc   -> SetLineWidth(2);
  h1_alphaData -> SetLineWidth(2);
  h1_alphaMc   -> Rebin(2);
  h1_alphaData -> Rebin(2);

  

  // To check the closure:                                                                                                   
  //                                                                                                                         
  // We make a comparison between the estimate and the distribution from data in the signal region                           
  // To make it more sensitive, we normalize both histos (which are smooth being generated with 2M events)                   
  // to the number of events that we really have in data                                                                     
  // Also we scale the errors to the errors in the data histo (bin per bin)                                                  

  // Loading the data dataset (signal region for closure)                                                                    
  // to normalize back the rooDataHist before fitting and get sensitive errors
  RooDataSet *dataSigRegion;
  if(!opts.getBoolVal("kinfit")) 
    dataSigRegion = getDataSet2("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_senzaMassCuts/Radion_Data_default_CSV.root", "myTrees", category);
  else
    dataSigRegion = getDataSet2("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_conKinFit_senzaMassCuts/Radion_Data_default_CSV.root", "myTrees", category);

  if (category==0)
    dataSigRegion = (RooDataSet*)dataSigRegion->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1)
    dataSigRegion = (RooDataSet*)dataSigRegion->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2)
    dataSigRegion = (RooDataSet*)datasigRegion->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
  float numEntries = (float)(dataSigRegion->numEntries());

  // putting it into an histogram                                                                                            
  TTree *treeData = dataset2tree(dataSigRegion);
  TH1F *h1_mggjj_data = new TH1F("h1_mggjj_data","h1_mggjj_data",50,200.,700.);
  h1_mggjj_data->Sumw2();
  treeData->Project("h1_mggjj_data","mggjj");

  // proper normalization for estimate and toys from "real" data                                                             
  h1_resultHisto->Scale( numEntries / (h1_resultHisto->Integral()) );
  h1_mggjj_genDataS->Scale( numEntries / (h1_mggjj_genDataS->Integral()) );
  if (h1_resultHisto->GetNbinsX() != h1_mggjj_genDataS->GetNbinsX()) cout << "problem" << endl;
  if (h1_resultHisto->GetNbinsX() != h1_mggjj_data->GetNbinsX())     cout << "problem" << endl;

  for (int ii=1; ii<=h1_mggjj_data->GetNbinsX(); ii++) {
    float thisRealError = h1_mggjj_data->GetBinError(ii);
    h1_mggjj_genDataS->SetBinError(ii,thisRealError);
  }

  h1_mggjj_genDataS->SetMinimum(0);
  h1_resultHisto->SetMinimum(0);


  // plots to check                                                                                                          
  TLegend *leg3;
  leg3 = new TLegend(0.35,0.55,0.90,0.80);
  leg3->SetFillStyle(0);
  leg3->SetBorderSize(0);
  leg3->SetTextSize(0.05);
  leg3->SetFillColor(0);
  leg3->AddEntry(h1_resultHisto,    "estimated from sidebands", "f");
  leg3->AddEntry(h1_mggjj_genDataS, "data in signal region",    "p");
 
  TCanvas myC2a("myC2a","",1);
  myC2a.cd();
  h1_resultHisto->Draw("hist");
  if (category==2)      myC2a.SaveAs("fitres/resultHisto_cat2.png");
  else if (category==1) myC2a.SaveAs("fitres/resultHisto_cat1.png");
  else if (category==0) myC2a.SaveAs("fitres/resultHisto_cat0.png");

  TCanvas myC2b("myC2b","",1);
  myC2b.cd();
  h1_mggjj_genDataS->Draw("pE");
  h1_resultHisto   ->Draw("samehist");
  h1_mggjj_genDataS->Draw("samepE");
  leg3->Draw();
  if (category==2)      myC2b.SaveAs("fitres/resultHistoCheck_cat2.png");
  else if (category==1) myC2b.SaveAs("fitres/resultHistoCheck_cat1.png");
  else if (category==0) myC2b.SaveAs("fitres/resultHistoCheck_cat0.png");
  if (category==2)      myC2b.SaveAs("fitres/resultHistoCheck_cat2.pdf");
  else if (category==1) myC2b.SaveAs("fitres/resultHistoCheck_cat1.pdf");
  else if (category==0) myC2b.SaveAs("fitres/resultHistoCheck_cat0.pdf");

  // plots to check alpha                                                                                                    
  TLegend *leg4;
  leg4 = new TLegend(0.4,0.4,0.65,0.65);
  leg4->SetFillStyle(0);
  leg4->SetBorderSize(0);
  leg4->SetTextSize(0.05);
  leg4->SetFillColor(0);
  leg4->AddEntry(h1_alphaMc,   "#alpha from data CS",  "l");
  leg4->AddEntry(h1_alphaData, "#alpha from data", "l");

  TCanvas myC2c("myC2c","",1);
  myC2c.cd();
  h1_alphaMc->DrawNormalized("hist");
  h1_alphaData->DrawNormalized("samehist");
  leg4->Draw();
  if (category==2)      myC2c.SaveAs("fitres/alpha_cat2.png");
  else if (category==1) myC2c.SaveAs("fitres/alpha_cat1.png");
  else if (category==0) myC2c.SaveAs("fitres/alpha_cat0.png");
  if (category==2)      myC2c.SaveAs("fitres/alpha_cat2.pdf");
  else if (category==1) myC2c.SaveAs("fitres/alpha_cat1.pdf");
  else if (category==0) myC2c.SaveAs("fitres/alpha_cat0.pdf");

  // useful root file
  TFile *myResultFile;
  if (category==2)      myResultFile = new TFile("fitres/myResultFile_cat2.root","RECREATE");
  else if (category==1) myResultFile = new TFile("fitres/myResultFile_cat1.root","RECREATE");
  else if (category==0) myResultFile = new TFile("fitres/myResultFile_cat0.root","RECREATE");
  myResultFile->cd();
  h1_resultHisto->Write();
  myResultFile->Close();


  // -----------------------------------------------------------------------                                                 
  // Now we fit the final distribution to get the PDF for the analysis      

  // Roodatahist of this histogram to fit with a landau
  RooRealVar meanL1("meanL1",   "meanL1", 300, 200., 400.);
  RooRealVar sigmaL1("sigmaL1", "sigmaL1", 40,  20.,  60.);
  RooLandau landau1("landau1",  "landau1", *mggjj, meanL1, sigmaL1);

  RooDataHist resultHistoRDH("resultHistoRDH", "resultHistoRDH", *mggjj, h1_resultHisto);
  landau1.fitTo(resultHistoRDH, RooFit::SumW2Error(kFALSE));    // chiara: secondo me deve essere kfalse!);
  resultHistoRDH.plotOn(plot3, RooFit::LineColor(kBlack));
  landau1.plotOn(plot3, RooFit::LineColor(kGreen));

  cout << endl;
  cout << "--------------------------------------------------------"    << endl;
  cout << "getting the fit result before renormalization"               << endl;
  cout << "mean: "  << meanL1.getVal()  << " +- " << meanL1.getError()  << endl;
  cout << "sigma: " << sigmaL1.getVal() << " +- " << sigmaL1.getError() << endl;
  cout << "--------------------------------------------------------"    << endl;

  TCanvas myC2("myC2","",1);
  myC2.cd();
  plot3->SetYTitle("Events");
  plot3->Draw();
  if      (category==2) myC2.SaveAs("fitres/resultHistoWithFit_cat2.png");
  else if (category==1) myC2.SaveAs("fitres/resultHistoWithFit_cat1.png");
  else if (category==0) myC2.SaveAs("fitres/resultHistoWithFit_cat0.png");



  // this is done with very small errors, because they come from 2M events for each histo                                    
  // First we rescale the errors of the histos used to make the final one to be representative                               
  // of the initial statistics, then we re-do the fit                                                                        

  // loading the dataset for data in low sideband                                                                            
  RooDataSet *dataL;
  if(!opts.getBoolVal("kinfit"))   
    dataL = getDataSet2("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_senzaMassCuts/Radion_Data_default_CSV.root", "myTrees", category);
  else
    dataL = getDataSet2("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_conKinFit_senzaMassCuts/Radion_Data_default_CSV.root", "myTrees", category);
  
  if (category==0)
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1)
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2)
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");

  // loading the dataset for data CS in low sideband                                                                              
  RooDataSet *mcL;    
  if(!opts.getBoolVal("kinfit"))   
    mcL = getDataSetCS("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_senzaMassCuts__CS/Radion_Data_default_CSV__withWeightsForSidebands.root", "myTrees_withWeight");  
  else
    mcL = getDataSetCS("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_conKinFit_senzaMassCuts__CS/Radion_Data_default_CSV__withWeightsForSidebands.root", "myTrees_withWeight");  
  
  if (category==0)
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1)
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2)
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");

  // loading the dataset for data CS in the signal region                                                                         
  RooDataSet *mcS;   
  if(!opts.getBoolVal("kinfit")) 
    mcS = getDataSetCS("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_senzaMassCuts__CS/Radion_Data_default_CSV__withWeightsForSidebands.root", "myTrees_withWeight");  
  else
    mcS = getDataSetCS("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_conKinFit_senzaMassCuts__CS/Radion_Data_default_CSV__withWeightsForSidebands.root", "myTrees_withWeight");  

  if (category==0)
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1)
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2)
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");


  // putting them all into histograms                                                                                        
  TTree *treeDataL = dataset2tree(dataL);
  TTree *treeMcL   = dataset2tree(mcL);
  TTree *treeMcS   = dataset2tree(mcS);

  TH1F *h1_dataL = new TH1F("h1_dataL","h1_dataL",50,200.,700.);
  TH1F *h1_mcL   = new TH1F("h1_mcL",  "h1_mcL",  50,200.,700.);
  TH1F *h1_mcS   = new TH1F("h1_mcS",  "h1_mcS",  50,200.,700.);
  h1_dataL  -> Sumw2();
  h1_mcL    -> Sumw2();
  h1_mcS    -> Sumw2();
  treeDataL -> Project("h1_dataL","mggjj");
  treeMcL   -> Project("h1_mcL","mggjj");
  treeMcS   -> Project("h1_mcS","mggjj");
  

  // now cloning previous histos to replace the errors                                                                       
  TH1F *h1c_resultHisto    = new TH1F("h1c_resultHisto","h1c_resultHisto",50,200.,700.);
  TH1F *h1c_mggjj_genMcS   = (TH1F*)h1_mggjj_genMcS->Clone("h1c_mggjj_genMcS");
  TH1F *h1c_mggjj_genMcL   = (TH1F*)h1_mggjj_genMcL->Clone("h1c_mggjj_genMcL");
  TH1F *h1c_mggjj_genDataL = (TH1F*)h1_mggjj_genDataL->Clone("h1c_mggjj_genDataL");
  h1c_resultHisto->Sumw2();

  for (int ii=1; ii<=h1c_resultHisto->GetNbinsX(); ii++) {
    float thisRealError=-999.;

    thisRealError = h1_mcS->GetBinError(ii);
    h1c_mggjj_genMcS->SetBinError(ii,thisRealError);

    thisRealError = h1_mcL->GetBinError(ii);
    h1c_mggjj_genMcL->SetBinError(ii,thisRealError);

    thisRealError = h1_dataL->GetBinError(ii);
    h1c_mggjj_genDataL->SetBinError(ii,thisRealError);
  }

  h1c_resultHisto->Add(h1c_mggjj_genMcS,1);
  h1c_resultHisto->Divide(h1c_mggjj_genMcL);
  h1c_resultHisto->Multiply(h1c_mggjj_genDataL);
  h1c_resultHisto->SetFillColor(kRed-9);


  // same checks as before, now with larger errors on the estimate                                                           
  h1c_resultHisto->Scale( numEntries / (h1c_resultHisto->Integral()) );
  h1c_resultHisto->SetMinimum(0);
  h1c_resultHisto->SetMarkerStyle(20);

  // New fit after proper normalization   
  RooRealVar meanL("meanL",   "meanL", 300, 200., 400.);
  RooRealVar sigmaL("sigmaL", "sigmaL", 40,  20.,  60.);
  RooLandau landau("landau", "landau", *mggjj, meanL, sigmaL);

  RooDataHist resultHistoRDH2("resultHistoRDH2", "resultHistoRDH2", *mggjj, h1c_resultHisto);
  landau.fitTo(resultHistoRDH2, RooFit::SumW2Error(kFALSE));    // chiara: secondo me deve essere kfalse!);
  resultHistoRDH2.plotOn(plot4, RooFit::LineColor(kBlack));
  landau.plotOn(plot4, RooFit::LineColor(kGreen));

  cout << endl;
  cout << "--------------------------------------------------------"  << endl;
  cout << "getting the fit result after renormalization"              << endl;
  cout << "mean: "  << meanL.getVal()  << " +- " << meanL.getError()  << endl;
  cout << "sigma: " << sigmaL.getVal() << " +- " << sigmaL.getError() << endl;
  cout << "--------------------------------------------------------"  << endl;
  cout << endl;

  // Fix the variables to the fit results for the remaining part
  meanL.setConstant(kTRUE);
  sigmaL.setConstant(kTRUE);


  // Prepare PDFs with modified parameters to graphically quantify errors
  float meanUp  = meanL.getVal() + meanL.getError(); 
  float meanDw  = meanL.getVal() - meanL.getError(); 
  float sigmaUp = sigmaL.getVal() + sigmaL.getError(); 
  float sigmaDw = sigmaL.getVal() - sigmaL.getError(); 
  RooRealVar meanLup("meanLup",   " meanLup", meanUp, meanUp, meanUp);
  RooRealVar meanLdw("meanLdw",    "meanLdw", meanDw, meanDw, meanDw);
  RooRealVar sigmaLup("sigmaLup",  "sigmaup", sigmaUp, sigmaUp, sigmaUp);
  RooRealVar sigmaLdw("sigmaLdw",  "sigmadw", sigmaDw, sigmaDw, sigmaDw);
  RooLandau landauMup("landauMup", "landauMup", *mggjj, meanLup, sigmaL);
  RooLandau landauMdw("landauMdw", "landauMdw", *mggjj, meanLdw, sigmaL);
  RooLandau landauSup("landauSup", "landauSup", *mggjj, meanL,   sigmaLup);
  RooLandau landauSdw("landauSdw", "landauSdw", *mggjj, meanL,   sigmaLdw);

  // Generating many events according to the fix landau shape and converting to a root tree
  TH1F *h1_mggjj_fit_many  = new TH1F("h1_mggjj_fit_many","h1_mggjj_fit_many",50,200.,700.);
  h1_mggjj_fit_many->Sumw2();
  RooDataSet *genDataMany = landau.generate(setqui,2000000,kTRUE,kFALSE);
  TTree *treeGenDataMany  = dataset2tree(genDataMany);
  treeGenDataMany->Project("h1_mggjj_fit_many","mggjj");
  if (h1_mggjj_fit_many->GetNbinsX() != h1_mggjj_data->GetNbinsX()) cout << "problem" << endl;
  h1_mggjj_fit_many -> SetFillColor(kGreen-9);

  // Now the same according pdfs with errors
  TH1F *h1_mggjj_fit_manyMup = new TH1F("h1_mggjj_fit_manyMup","h1_mggjj_fit_manyMup",50,200.,700.);
  h1_mggjj_fit_manyMup->Sumw2();
  RooDataSet *genDataManyMup = landauMup.generate(setqui,2000000,kTRUE,kFALSE);
  TTree *treeGenDataManyMup  = dataset2tree(genDataManyMup);
  treeGenDataManyMup->Project("h1_mggjj_fit_manyMup","mggjj");

  TH1F *h1_mggjj_fit_manyMdw = new TH1F("h1_mggjj_fit_manyMdw","h1_mggjj_fit_manyMdw",50,200.,700.);
  h1_mggjj_fit_manyMdw->Sumw2();
  RooDataSet *genDataManyMdw = landauMdw.generate(setqui,2000000,kTRUE,kFALSE);
  TTree *treeGenDataManyMdw  = dataset2tree(genDataManyMdw);
  treeGenDataManyMdw->Project("h1_mggjj_fit_manyMdw","mggjj");

  TH1F *h1_mggjj_fit_manySup = new TH1F("h1_mggjj_fit_manySup","h1_mggjj_fit_manySup",50,200.,700.);
  h1_mggjj_fit_manySup->Sumw2();
  RooDataSet *genDataManySup = landauSup.generate(setqui,2000000,kTRUE,kFALSE);
  TTree *treeGenDataManySup  = dataset2tree(genDataManySup);
  treeGenDataManySup->Project("h1_mggjj_fit_manySup","mggjj");

  TH1F *h1_mggjj_fit_manySdw = new TH1F("h1_mggjj_fit_manySdw","h1_mggjj_fit_manySdw",50,200.,700.);
  h1_mggjj_fit_manySdw->Sumw2();
  RooDataSet *genDataManySdw = landauSdw.generate(setqui,2000000,kTRUE,kFALSE);
  TTree *treeGenDataManySdw  = dataset2tree(genDataManySdw);
  treeGenDataManySdw->Project("h1_mggjj_fit_manySdw","mggjj");

  h1_mggjj_fit_manySup->SetLineColor(1);
  h1_mggjj_fit_manySdw->SetLineColor(1);
  h1_mggjj_fit_manyMup->SetLineColor(1);
  h1_mggjj_fit_manyMdw->SetLineColor(1);
  h1_mggjj_fit_manySup->SetLineWidth(2);
  h1_mggjj_fit_manySdw->SetLineWidth(2);
  h1_mggjj_fit_manyMup->SetLineWidth(2);
  h1_mggjj_fit_manyMdw->SetLineWidth(2);

  // normalization to the number of events in data SR
  h1_mggjj_fit_many->Scale(numEntries/(h1_mggjj_fit_many->Integral()));
  h1_mggjj_fit_manyMup->Scale(numEntries/(h1_mggjj_fit_manyMup->Integral()));
  h1_mggjj_fit_manyMdw->Scale(numEntries/(h1_mggjj_fit_manyMdw->Integral()));
  h1_mggjj_fit_manySup->Scale(numEntries/(h1_mggjj_fit_manySup->Integral()));
  h1_mggjj_fit_manySdw->Scale(numEntries/(h1_mggjj_fit_manySdw->Integral()));

  // comparison plots between fit and the original dataset
  float highFit = h1_mggjj_fit_many->GetMaximum();
  if ( highFit<(h1_mggjj_genDataS->GetMaximum()) )    highFit = h1_mggjj_genDataS->GetMaximum();
  if ( highFit<(h1_mggjj_fit_manyMup->GetMaximum()) ) highFit = h1_mggjj_fit_manyMup->GetMaximum();
  if ( highFit<(h1_mggjj_fit_manyMdw->GetMaximum()) ) highFit = h1_mggjj_fit_manyMdw->GetMaximum();
  if ( highFit<(h1_mggjj_fit_manySup->GetMaximum()) ) highFit = h1_mggjj_fit_manySup->GetMaximum();
  if ( highFit<(h1_mggjj_fit_manySdw->GetMaximum()) ) highFit = h1_mggjj_fit_manySdw->GetMaximum();
  h1_mggjj_genDataS->SetMaximum((highFit+0.1));
  h1_mggjj_fit_many->SetMaximum((highFit+0.1));
  h1_mggjj_fit_manyMup->SetMaximum((highFit+0.1));
  h1_mggjj_fit_manyMdw->SetMaximum((highFit+0.1));
  h1_mggjj_fit_manySup->SetMaximum((highFit+0.1));
  h1_mggjj_fit_manySdw->SetMaximum((highFit+0.1));
  
  TLegend *leg3;
  leg3 = new TLegend(0.5,0.6,0.75,0.85);
  leg3->SetFillStyle(0);
  leg3->SetBorderSize(0);
  leg3->SetTextSize(0.05);
  leg3->SetFillColor(0);
  leg3->AddEntry(h1_mggjj_genDataS, "data", "p");
  leg3->AddEntry(h1_mggjj_fit_many, "from sidebands",  "f");
  leg3->AddEntry(h1_mggjj_fit_manySup, "from sidebands (syst)", "l");
 
  TCanvas *myC4b = new TCanvas("myC4b","",1);
  h1_mggjj_fit_many->Draw("hist");   
  h1_mggjj_genDataS->Draw("pEsame");
  h1_mggjj_fit_manySup->Draw("histsame");
  h1_mggjj_fit_manySdw->Draw("histsame");
  h1_mggjj_fit_manyMup->Draw("histsame");
  h1_mggjj_fit_manyMdw->Draw("histsame");
  leg3->Draw();
  if (category==2)      myC4b->SaveAs("fitres/closureManyToys_cat2.png");
  else if (category==1) myC4b->SaveAs("fitres/closureManyToys_cat1.png");
  else if (category==0) myC4b->SaveAs("fitres/closureManyToys_cat0.png");

  TCanvas *myC5b = new TCanvas("myC5b","",1);
  h1_mggjj_fit_many->Draw("hist");   
  h1_mggjj_genDataS->Draw("pEsame");
  h1_mggjj_fit_manySup->Draw("histsame");
  h1_mggjj_fit_manySdw->Draw("histsame");
  h1_mggjj_fit_manyMup->Draw("histsame");
  h1_mggjj_fit_manyMdw->Draw("histsame");
  h1_mggjj_fit_many->SetMinimum(0.0001);
  h1_mggjj_genDataS->SetMinimum(0.0001);
  h1_mggjj_fit_manySup->SetMinimum(0.0001);
  h1_mggjj_fit_manySdw->SetMinimum(0.0001);
  h1_mggjj_fit_manyMup->SetMinimum(0.0001);
  h1_mggjj_fit_manyMdw->SetMinimum(0.0001);
  myC5b->SetLogy(1);
  leg3->Draw();
  if (category==2)      myC5b->SaveAs("fitres/closureManyToysLog_cat2.png");
  else if (category==1) myC5b->SaveAs("fitres/closureManyToysLog_cat1.png");
  else if (category==0) myC5b->SaveAs("fitres/closureManyToysLog_cat0.png");
  myC5b->SetLogy(0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlotGGPerAlpha_closure_highMass_meth2(int category) {    
  
  cout << "final check at high mass, method2, category = " << category << endl;

  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma#gamma} [GeV]",  100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);
  RooRealVar* mggjj        = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 300., 1000.);   
  RooRealVar* btagCategory = new RooRealVar("btagCategory", "btagCategory",            -0.9, 2.1);
  theFit.AddFlatFileColumn(massggnewvtx);
  theFit.AddFlatFileColumn(mjj);
  theFit.AddFlatFileColumn(mggjj);
  theFit.AddFlatFileColumn(btagCategory);

  // define a fit model
  theFit.addModel   ("myFit", "HtoGG");
  theFit.addSpecies ("myFit", "bkg",  "Bkg Component");
  theFit.addPdfWName("myFit", "bkg" , "mggjj",  "Expo", "bkg_Mass");      
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // for random generation
  TDatime *now = new TDatime();
  int today    = now->GetDate();
  int clock    = now->GetTime();
  int seed     = today+clock+65539;
  RooRandom::randomGenerator()->SetSeed(seed);

  // initializations for the plots
  TCanvas *c = new TCanvas("c","fitResult");
  RooRealVar* Var = theFit.RealObservable("mggjj");           
  double min      = Var->getMin();
  double max      = Var->getMax();
  RooPlot *plot   = Var->frame(min,max,25);
  RooPlot *plot2  = Var->frame(min,max,25);
  RooPlot *plot3  = Var->frame(min,max,25);
  RooPlot *plot4  = Var->frame(min,max,25);



  // Now reading the previous fit results for sidebands and signal region (data and mc). 
  // Generate events according to those distributions
  RooAbsPdf *thePdfLMc, *thePdfHMc, *thePdfSMc;
  RooAbsPdf *thePdfLData;
  RooArgSet setqui(*mggjj);
  
  cout << endl;
  cout << "Reading results from low sideband fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_lowSideband_cat2_mc_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_mc_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_mc_closure.config");  
  thePdfLMc = theFit.getPdf("myFit");
  thePdfLMc->plotOn(plot, RooFit::LineColor(kBlue));
  RooDataSet *genMcL = thePdfLMc->generate(setqui,2000000,kTRUE,kFALSE);

  cout << endl;
  cout << "Reading results from high sideband fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_highSideband_cat2_mc_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_highSideband_cat1_mc_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_highSideband_cat0_mc_closure.config");  
  thePdfHMc = theFit.getPdf("myFit");
  thePdfHMc->plotOn(plot, RooFit::LineColor(kGreen));

  cout << endl;
  cout << "Reading results from signal region fit in MC" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_signalRegion_cat2_mc_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_signalRegion_cat1_mc_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_signalRegion_cat0_mc_closure.config");  
  thePdfSMc = theFit.getPdf("myFit");
  thePdfSMc->plotOn(plot, RooFit::LineColor(kRed));
  RooDataSet *genMcS = thePdfSMc->generate(setqui,2000000,kTRUE,kFALSE);

  cout << endl;
  cout << "Reading results from low sideband fit in Data" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_lowSideband_cat2_data_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_data_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_lowSideband_cat0_data_closure.config");  
  thePdfLData = theFit.getPdf("myFit");
  thePdfLData->plotOn(plot2, RooFit::LineColor(kBlue));
  RooDataSet *genDataL = thePdfLData->generate(setqui,2000000,kTRUE,kFALSE);

  cout << endl;
  cout << "Reading results from signal region fit in Data" << endl;
  if (category==2) theFit.initialize("fitres/fitBackground_signalRegion_cat2_data_closure.config");  
  if (category==1) theFit.initialize("fitres/fitBackground_signalRegion_cat1_data_closure.config");  
  if (category==0) theFit.initialize("fitres/fitBackground_signalRegion_cat0_data_closure.config");  
  thePdfSData = theFit.getPdf("myFit");
  thePdfSData->plotOn(plot2, RooFit::LineColor(kRed));
  RooDataSet *genDataS = thePdfSData->generate(setqui,2000000,kTRUE,kFALSE);


  // plot from the original pdfs from MC
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
  leg->AddEntry(myH_fuffaLR, "low mgg sideband (mc)",  "l");
  leg->AddEntry(myH_fuffaHR, "high mgg sideband (mc)", "l");
  leg->AddEntry(myH_fuffaSR, "mgg signal region (mc)", "l");

  TLegend *leg2;
  leg2 = new TLegend(0.5,0.5,0.75,0.75);
  leg2->SetFillStyle(0);
  leg2->SetBorderSize(0);
  leg2->SetTextSize(0.05);
  leg2->SetFillColor(0);
  leg2->AddEntry(myH_fuffaLR, "low mgg sideband (data)",  "l");
  leg2->AddEntry(myH_fuffaSR, "mgg signal region (data)", "l");

  TCanvas *myC = new TCanvas("myC","",1);
  myC->cd();
  plot->SetYTitle("Events");
  plot->Draw();
  leg->Draw();
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat2_closure.png");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat1_closure.png");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat0_closure.png");  
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat2_closure.pdf");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat1_closure.pdf");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat0_closure.pdf");  

  plot2->SetYTitle("Events");
  plot2->Draw();
  leg2->Draw();
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat2_closure.png");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat1_closure.png");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat0_closure.png");  
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat2_closure.pdf");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat1_closure.pdf");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToData_cat0_closure.pdf");  


  // Trees and histos from the previous toys
  TTree *treeGenDataS = dataset2tree(genDataS);
  TTree *treeGenDataL = dataset2tree(genDataL);
  TTree *treeGenMcS   = dataset2tree(genMcS);
  TTree *treeGenMcL   = dataset2tree(genMcL);

  TH1F *h1_mggjj_genMcL, *h1_mggjj_genMcS, *h1_mggjj_genDataL, *h1_mggjj_genDataS;
  h1_mggjj_genMcL   = new TH1F("h1_mggjj_genMcL",  "h1_mggjj_genMcL",  50,300.,1000.);
  h1_mggjj_genMcS   = new TH1F("h1_mggjj_genMcS",  "h1_mggjj_genMcS",  50,300.,1000.);
  h1_mggjj_genDataL = new TH1F("h1_mggjj_genDataL","h1_mggjj_genDataL",50,300.,1000.);
  h1_mggjj_genDataS = new TH1F("h1_mggjj_genDataS","h1_mggjj_genDataS",50,300.,1000.);
  h1_mggjj_genMcL->Sumw2();
  h1_mggjj_genMcS->Sumw2();
  h1_mggjj_genDataL->Sumw2();
  h1_mggjj_genDataS->Sumw2();
  treeGenMcL  ->Project("h1_mggjj_genMcL",  "mggjj");
  treeGenMcS  ->Project("h1_mggjj_genMcS",  "mggjj");
  treeGenDataL->Project("h1_mggjj_genDataL","mggjj");
  treeGenDataS->Project("h1_mggjj_genDataS","mggjj");

  h1_mggjj_genMcL->SetLineColor(kBlue);
  h1_mggjj_genMcS->SetLineColor(kRed);
  h1_mggjj_genDataL->SetLineColor(kBlue);
  h1_mggjj_genDataS->SetLineColor(kRed);
  h1_mggjj_genDataS->SetMarkerColor(kRed);
  h1_mggjj_genMcL   -> Scale(1./(h1_mggjj_genMcL->Integral()));
  h1_mggjj_genMcS   -> Scale(1./(h1_mggjj_genMcS->Integral()));
  h1_mggjj_genDataL -> Scale(1./(h1_mggjj_genDataL->Integral()));
  h1_mggjj_genDataS -> Scale(1./(h1_mggjj_genDataS->Integral()));

  // to check wrt before
  h1_mggjj_genMcL->Draw("hist");
  h1_mggjj_genMcS->Draw("samehist");
  if (category==2) myC->SaveAs("fitres/mGGJJ_histosObtainedFromMcToys_cat2.png");
  else if (category==1) myC->SaveAs("fitres/mGGJJ_histosObtainedFromMcToys_cat1.png");
  else if (category==0) myC->SaveAs("fitres/mGGJJ_histosObtainedFromMcToys_cat0.png"); 

  h1_mggjj_genDataL->Draw("hist");
  h1_mggjj_genDataS->Draw("samehist");
  if (category==2) myC->SaveAs("fitres/mGGJJ_histosObtainedFromDataToys_cat2.png");
  else if (category==1) myC->SaveAs("fitres/mGGJJ_histosObtainedFromDataToys_cat1.png");
  else if (category==0) myC->SaveAs("fitres/mGGJJ_histosObh1_mggjj_genDataStainedFromDataToys_cat0.png"); 





  // --------------------------------------------------------------------------------------------------------------------------
  // Now making an histogram which is the product of previous ones and which should represent the data in the signal region
  // ==> this is our background estimate <==
  TH1F *h1_resultHisto = new TH1F("h1_resultHisto", "h1_resultHisto", 50,300.,1000.); 
  h1_resultHisto->Sumw2();
  h1_resultHisto->Add(h1_mggjj_genMcS,1);
  h1_resultHisto->Divide(h1_mggjj_genMcL);
  h1_resultHisto->Multiply(h1_mggjj_genDataL);
  h1_resultHisto->SetFillColor(kGreen-9);

  // also alpha histos may be useful
  TH1F *h1_alphaMc   = new TH1F("h1_alphaMc",   "h1_alphaMc",   50,300.,1000.);
  TH1F *h1_alphaData = new TH1F("h1_alphaData", "h1_alphaData", 50,300.,1000.);
  h1_alphaMc -> Sumw2();
  h1_alphaMc -> Add(h1_mggjj_genMcS,1);
  h1_alphaMc -> Divide(h1_mggjj_genMcL);
  h1_alphaData -> Sumw2();
  h1_alphaData -> Add(h1_mggjj_genDataS,1);
  h1_alphaData -> Divide(h1_mggjj_genDataL);
  h1_alphaMc   -> SetLineColor(6);
  h1_alphaData -> SetLineColor(4);
  h1_alphaMc   -> SetLineWidth(2);
  h1_alphaData -> SetLineWidth(2);
  h1_alphaMc   -> Rebin(2);
  h1_alphaData -> Rebin(2);
  

  // To check the closure:
  // 
  // We make a comparison between the estimate and the distribution from data in the signal region
  // To make it more sensitive, we normalize both histos (which are smooth being generated with 2M events) 
  // to the number of events that we really have in data
  // Also we scale the errors to the errors in the data histo (bin per bin)   

  // Loading the data dataset (signal region for closure) 
  // to normalize back the rooDataHist before fitting and get sensitive errors
  RooDataSet *dataSigRegion;
  if(!opts.getBoolVal("kinfit")) 
    dataSigRegion = getDataSet2("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_senzaMassCuts/Radion_Data_default_CSV.root", "myTrees", category);
  else
    dataSigRegion = getDataSet2("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_conKinFit_senzaMassCuts/Radion_Data_default_CSV.root", "myTrees", category);

  if (category==0)                 
    dataSigRegion = (RooDataSet*)dataSigRegion->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
  else if (category==1) 
    dataSigRegion = (RooDataSet*)dataSigRegion->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
  else if (category==2) 
    dataSigRegion = (RooDataSet*)datasigRegion->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
  float numEntries = (float)(dataSigRegion->numEntries()); 


  // putting it into an histogram 
  TTree *treeData = dataset2tree(dataSigRegion);
  TH1F *h1_mggjj_data = new TH1F("h1_mggjj_data","h1_mggjj_data",50,300.,1000.);
  h1_mggjj_data->Sumw2();
  treeData->Project("h1_mggjj_data","mggjj");


  // proper normalization for estimate and toys from "real" data
  h1_resultHisto->Scale( numEntries / (h1_resultHisto->Integral()) );
  h1_mggjj_genDataS->Scale( numEntries / (h1_mggjj_genDataS->Integral()) );
  if (h1_resultHisto->GetNbinsX() != h1_mggjj_genDataS->GetNbinsX()) cout << "problem" << endl;
  if (h1_resultHisto->GetNbinsX() != h1_mggjj_data->GetNbinsX())     cout << "problem" << endl;
  
  for (int ii=1; ii<=h1_mggjj_data->GetNbinsX(); ii++) {
    float thisRealError = h1_mggjj_data->GetBinError(ii);
    h1_mggjj_genDataS->SetBinError(ii,thisRealError);
  }

  h1_mggjj_genDataS->SetMinimum(0);
  h1_resultHisto->SetMinimum(0);


  // plots to check
  TLegend *leg3;
  leg3 = new TLegend(0.5,0.5,0.75,0.75);
  leg3->SetFillStyle(0);
  leg3->SetBorderSize(0);
  leg3->SetTextSize(0.05);
  leg3->SetFillColor(0);
  leg3->AddEntry(h1_resultHisto,    "estimated from sideband", "f");
  leg3->AddEntry(h1_mggjj_genDataS, "data in signal region",  "p");

  TCanvas myC2a("myC2a","",1);
  myC2a.cd();
  h1_resultHisto->Draw("hist");
  if (category==2)      myC2a.SaveAs("fitres/resultHisto_cat2.png");
  else if (category==1) myC2a.SaveAs("fitres/resultHisto_cat1.png");
  else if (category==0) myC2a.SaveAs("fitres/resultHisto_cat0.png"); 

  TCanvas myC2b("myC2b","",1);
  myC2b.cd();
  h1_mggjj_genDataS->Draw("pE");
  h1_resultHisto   ->Draw("samehist");
  h1_mggjj_genDataS->Draw("samepE");
  leg3->Draw();
  if (category==2)      myC2b.SaveAs("fitres/resultHistoCheck_cat2.png");
  else if (category==1) myC2b.SaveAs("fitres/resultHistoCheck_cat1.png");
  else if (category==0) myC2b.SaveAs("fitres/resultHistoCheck_cat0.png"); 
  if (category==2)      myC2b.SaveAs("fitres/resultHistoCheck_cat2.pdf");
  else if (category==1) myC2b.SaveAs("fitres/resultHistoCheck_cat1.pdf");
  else if (category==0) myC2b.SaveAs("fitres/resultHistoCheck_cat0.pdf"); 

  // plots to check alpha
  TLegend *leg4;
  leg4 = new TLegend(0.5,0.5,0.75,0.75);
  leg4->SetFillStyle(0);
  leg4->SetBorderSize(0);
  leg4->SetTextSize(0.05);
  leg4->SetFillColor(0);
  leg4->AddEntry(h1_alphaMc,   "#alpha from MC",  "l");
  leg4->AddEntry(h1_alphaData, "#alpha from data", "l");

  TCanvas myC2c("myC2c","",1);
  myC2c.cd();
  h1_alphaData->DrawNormalized("hist");
  h1_alphaMc->DrawNormalized("samehist");
  leg4->Draw();
  if (category==2)      myC2c.SaveAs("fitres/alpha_cat2.png");
  else if (category==1) myC2c.SaveAs("fitres/alpha_cat1.png");
  else if (category==0) myC2c.SaveAs("fitres/alpha_cat0.png"); 
  if (category==2)      myC2c.SaveAs("fitres/alpha_cat2.pdf");
  else if (category==1) myC2c.SaveAs("fitres/alpha_cat1.pdf");
  else if (category==0) myC2c.SaveAs("fitres/alpha_cat0.pdf"); 


  
  // -----------------------------------------------------------------------
  // Now we fit the final distribution to get the PDF for the analysis

  // Roodatahist of this histogram to fit with an exponential
  RooRealVar expE1("expE1",   "expE1", -0.01, -0.5, 0.);   
  RooExponential exp1("exp1", "exp1", *mggjj, expE1);

  RooDataHist resultHistoRDH("resultHistoRDH", "resultHistoRDH", *mggjj, h1_resultHisto);
  exp1.fitTo(resultHistoRDH, RooFit::SumW2Error(kFALSE));    // chiara: secondo me deve essere kfalse!);
  resultHistoRDH.plotOn(plot3, RooFit::LineColor(kBlack));
  exp1.plotOn(plot3, RooFit::LineColor(kGreen));

  cout << endl;
  cout << "--------------------------------------------------------"  << endl;
  cout << "getting the fit result before renormalization"             << endl;
  cout << "exp: "  << expE1.getVal()  << " +- " << expE1.getError()   << endl;
  cout << "--------------------------------------------------------"  << endl;

  TCanvas myC2("myC2","",1);
  myC2.cd();
  plot3->SetYTitle("Events");
  plot3->Draw();
  if      (category==2) myC2.SaveAs("fitres/resultHistoWithFit_cat2.png");
  else if (category==1) myC2.SaveAs("fitres/resultHistoWithFit_cat1.png");
  else if (category==0) myC2.SaveAs("fitres/resultHistoWithFit_cat0.png");




  
  // this is done with very small errors, because they come from 2M events for each histo
  // First we rescale the errors of the histos used to make the final one to be representative 
  // of the initial statistics, then we re-do the fit
  
  // loading the dataset for data in low sideband
  RooDataSet *dataL;
  if(!opts.getBoolVal("kinfit"))   
    dataL = getDataSet2("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_senzaMassCuts/Radion_Data_default_CSV.root", "myTrees", category);
  else
    dataL = getDataSet2("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_conKinFit_senzaMassCuts/Radion_Data_default_CSV.root", "myTrees", category);
  
  if (category==0)                 
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
  else if (category==1) 
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
  else if (category==2) 
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");
  
  // loading the dataset for MC in low sideband
  RooDataSet *mcL;
  if(!opts.getBoolVal("kinfit"))    
    mcL = getDataSet("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_senzaMassCuts/Radion_diphojet_sherpa_8TeV_default_CSV.root", "myTrees", true);
  else
    mcL = getDataSet("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_conKinFit_senzaMassCuts/Radion_diphojet_sherpa_8TeV_default_CSV.root", "myTrees", true);

  if (category==0)                 
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
  else if (category==1) 
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
  else if (category==2) 
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=110 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");


  // loading the dataset for MC in the signal region
  RooDataSet *mcS;
  if(!opts.getBoolVal("kinfit"))    
    mcS = getDataSet("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_senzaMassCuts/Radion_diphojet_sherpa_8TeV_default_CSV.root", "myTrees", true);
  else
    mcS = getDataSet("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_conKinfit_senzaMassCuts/Radion_diphojet_sherpa_8TeV_default_CSV.root", "myTrees", true);

  if (category==0)                 
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==2");
  else if (category==1) 
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300 && btagCategory==1");
  else if (category==2) 
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>110 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<1000 && mggjj>300");

  // putting them all into histograms 
  TTree *treeDataL = dataset2tree(dataL);
  TTree *treeMcL   = dataset2tree(mcL);
  TTree *treeMcS   = dataset2tree(mcS);

  TH1F *h1_dataL = new TH1F("h1_dataL","h1_dataL",50,300.,1000.);
  TH1F *h1_mcL   = new TH1F("h1_mcL",  "h1_mcL",  50,300.,1000.);
  TH1F *h1_mcS   = new TH1F("h1_mcS",  "h1_mcS",  50,300.,1000.);
  h1_dataL  -> Sumw2();
  h1_mcL    -> Sumw2();
  h1_mcS    -> Sumw2();
  treeDataL -> Project("h1_dataL","mggjj");
  treeMcL   -> Project("h1_mcL","mggjj");
  treeMcS   -> Project("h1_mcS","mggjj");

  
  // now cloning previous histos to replace the errors
  TH1F *h1c_resultHisto    = new TH1F("h1c_resultHisto","h1c_resultHisto",50,300.,1000.);
  TH1F *h1c_mggjj_genMcS   = (TH1F*)h1_mggjj_genMcS->Clone("h1c_mggjj_genMcS");
  TH1F *h1c_mggjj_genMcL   = (TH1F*)h1_mggjj_genMcL->Clone("h1c_mggjj_genMcL");
  TH1F *h1c_mggjj_genDataL = (TH1F*)h1_mggjj_genDataL->Clone("h1c_mggjj_genDataL");
  h1c_resultHisto->Sumw2();
  // h1c_mggjj_genMcS->Sumw2();
  // h1c_mggjj_genMcL->Sumw2();
  // h1c_mggjj_genDataL->Sumw2();

  for (int ii=1; ii<=h1c_resultHisto->GetNbinsX(); ii++) {
    float thisRealError=-999.;
    
    thisRealError = h1_mcS->GetBinError(ii);
    h1c_mggjj_genMcS->SetBinError(ii,thisRealError);

    thisRealError = h1_mcL->GetBinError(ii);
    h1c_mggjj_genMcL->SetBinError(ii,thisRealError);
    
    thisRealError = h1_dataL->GetBinError(ii);
    h1c_mggjj_genDataL->SetBinError(ii,thisRealError);
  }

  h1c_resultHisto->Add(h1c_mggjj_genMcS,1);
  h1c_resultHisto->Divide(h1c_mggjj_genMcL);
  h1c_resultHisto->Multiply(h1c_mggjj_genDataL);
  h1c_resultHisto->SetFillColor(kRed-9);
  

  // same checks as before, now with larger errors on the estimate  
  h1c_resultHisto->Scale( numEntries / (h1c_resultHisto->Integral()) );
  h1c_resultHisto->SetMinimum(0);
  h1c_resultHisto->SetMarkerStyle(20);

  /*
  TCanvas myC3b("myC3b","",1);
  myC3b.cd();
  h1_mggjj_genDataS->Draw("pE");
  h1c_resultHisto  ->Draw("samepE");
  h1_mggjj_genDataS->Draw("samepE");
  if (category==2)      myC3b.SaveAs("fitres/resultHistoCheck_withLargerErrors_cat2.png");
  else if (category==1) myC3b.SaveAs("fitres/resultHistoCheck_withLargerErrors_cat1.png");
  else if (category==0) myC3b.SaveAs("fitres/resultHistoCheck_withLargerErrors_cat0.png"); 
  */


  // New fit after proper normalization 
  RooRealVar expE("expE","expE", -0.01, -0.5, 0.);   
  RooExponential exp("exp","exp",*mggjj, expE);

  RooDataHist resultHistoRDH2("resultHistoRDH2", "resultHistoRDH2", *mggjj, h1c_resultHisto);
  exp.fitTo(resultHistoRDH2, RooFit::SumW2Error(kFALSE));    // chiara: secondo me deve essere kfalse!);
  resultHistoRDH2.plotOn(plot4, RooFit::LineColor(kBlack));
  exp.plotOn(plot4, RooFit::LineColor(kGreen));

  cout << endl;
  cout << "--------------------------------------------------------" << endl;
  cout << "getting the fit result after renormalization"             << endl;
  cout << "exp: "  << expE.getVal()  << " +- " << expE.getError()    << endl;
  cout << "--------------------------------------------------------" << endl;
  cout << endl;

  myC2.cd();
  plot4->SetYTitle("Events");
  plot4->Draw();
  if      (category==2) myC2.SaveAs("fitres/resultHistoWithFitNormalized_cat2.png");
  else if (category==1) myC2.SaveAs("fitres/resultHistoWithFitNormalized_cat1.png");
  else if (category==0) myC2.SaveAs("fitres/resultHistoWithFitNormalized_cat0.png");


  // Fix the variables to the fit results for the remaining part
  expE.setConstant(kTRUE);


  // Prepare PDFs with modified parameters to graphically quantify errors
  float expUp = expE.getVal() + expE.getError(); 
  float expDw = expE.getVal() - expE.getError(); 
  RooRealVar expEup("expEup", "expEup", expUp, expUp, expUp);
  RooRealVar expEdw("expEdw", "expEdw", expDw, expDw, expDw);
  RooExponential expup("expup", "expup", *mggjj, expEup);
  RooExponential expdw("expdw", "expdw", *mggjj, expEdw);



  // Generating many events according to the fix exponential shape and converting to a root tree
  TH1F *h1_mggjj_fit_many  = new TH1F("h1_mggjj_fit_many","h1_mggjj_fit_many",50,300.,1000.);
  h1_mggjj_fit_many->Sumw2();
  RooDataSet *genDataMany = exp.generate(setqui,2000000,kTRUE,kFALSE);
  TTree *treeGenDataMany  = dataset2tree(genDataMany);
  treeGenDataMany->Project("h1_mggjj_fit_many","mggjj");
  if (h1_mggjj_fit_many->GetNbinsX() != h1_mggjj_data->GetNbinsX()) cout << "problem" << endl;
  h1_mggjj_fit_many -> SetFillColor(kGreen-9); 

  // Now the same according pdfs with errors
  TH1F *h1_mggjj_fit_manyEup = new TH1F("h1_mggjj_fit_manyEup","h1_mggjj_fit_manyEup",50,300.,1000.);
  h1_mggjj_fit_manyEup->Sumw2();
  RooDataSet *genDataManyEup = expup.generate(setqui,2000000,kTRUE,kFALSE);
  TTree *treeGenDataManyEup  = dataset2tree(genDataManyEup);
  treeGenDataManyEup->Project("h1_mggjj_fit_manyEup","mggjj");

  TH1F *h1_mggjj_fit_manyEdw = new TH1F("h1_mggjj_fit_manyEdw","h1_mggjj_fit_manyEdw",50,300.,1000.);
  h1_mggjj_fit_manyEdw->Sumw2();
  RooDataSet *genDataManyEdw = expdw.generate(setqui,2000000,kTRUE,kFALSE);
  TTree *treeGenDataManyEdw  = dataset2tree(genDataManyEdw);
  treeGenDataManyEdw->Project("h1_mggjj_fit_manyEdw","mggjj");

  h1_mggjj_fit_manyEup->SetLineColor(1);
  h1_mggjj_fit_manyEdw->SetLineColor(1);
  h1_mggjj_fit_manyEup->SetLineWidth(2);
  h1_mggjj_fit_manyEdw->SetLineWidth(2);

  // normalization to the number of events in data SR
  h1_mggjj_fit_many->Scale(numEntries/(h1_mggjj_fit_many->Integral()));
  h1_mggjj_fit_manyEup->Scale(numEntries/(h1_mggjj_fit_manyEup->Integral()));
  h1_mggjj_fit_manyEdw->Scale(numEntries/(h1_mggjj_fit_manyEdw->Integral()));
  
  // comparison plots between fit and the original dataset
  float highFit = h1_mggjj_fit_many->GetMaximum(); 
  if ( highFit<(h1_mggjj_genDataS->GetMaximum()) )    highFit = h1_mggjj_genDataS->GetMaximum();
  if ( highFit<(h1_mggjj_fit_manyEup->GetMaximum()) ) highFit = h1_mggjj_fit_manyEup->GetMaximum();
  if ( highFit<(h1_mggjj_fit_manyEdw->GetMaximum()) ) highFit = h1_mggjj_fit_manyEdw->GetMaximum();
  h1_mggjj_fit_many    -> SetMaximum((highFit+0.1));
  h1_mggjj_genDataS    -> SetMaximum((highFit+0.1));
  h1_mggjj_fit_manyEup -> SetMaximum((highFit+0.1));
  h1_mggjj_fit_manyEdw -> SetMaximum((highFit+0.1));

  TLegend *leg3;
  leg3 = new TLegend(0.5,0.7,0.75,0.95);
  leg3->SetFillStyle(0);
  leg3->SetBorderSize(0);
  leg3->SetTextSize(0.05);
  leg3->SetFillColor(0);
  leg3->AddEntry(h1_mggjj_genDataS, "data", "p");
  leg3->AddEntry(h1_mggjj_fit_many, "from sidebands",  "f");
  leg3->AddEntry(h1_mggjj_fit_manyEup, "from sidebands (syst)", "l");

  TCanvas *myC4b = new TCanvas("myC4b","",1);
  h1_mggjj_fit_many->Draw("hist");   
  h1_mggjj_genDataS->Draw("pEsame");
  h1_mggjj_fit_manyEup->Draw("histsame");
  h1_mggjj_fit_manyEdw->Draw("histsame");
  leg3->Draw();
  if (category==2)      myC4b->SaveAs("fitres/closureManyToys_cat2.png");
  else if (category==1) myC4b->SaveAs("fitres/closureManyToys_cat1.png");
  else if (category==0) myC4b->SaveAs("fitres/closureManyToys_cat0.png");

  TCanvas *myC5b = new TCanvas("myC5b","",1);
  h1_mggjj_fit_many->Draw("hist");   
  h1_mggjj_genDataS->Draw("pEsame");
  h1_mggjj_fit_manyEup->Draw("histsame");
  h1_mggjj_fit_manyEdw->Draw("histsame");
  h1_mggjj_fit_many->SetMinimum(0.0001);
  h1_mggjj_genDataS->SetMinimum(0.0001);
  h1_mggjj_fit_manyEdw->SetMinimum(0.0001);
  h1_mggjj_fit_manyEup->SetMinimum(0.0001);
  myC5b->SetLogy(1);
  leg3->Draw();
  if (category==2)      myC5b->SaveAs("fitres/closureManyToysLog_cat2.png");
  else if (category==1) myC5b->SaveAs("fitres/closureManyToysLog_cat1.png");
  else if (category==0) myC5b->SaveAs("fitres/closureManyToysLog_cat0.png");
  myC5b->SetLogy(0);
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

  // w/wo kinematic fit                                                                                                 
  if(opts.getBoolVal("kinfit"))
    cout << "we're using a kinematic fit"     << endl;
  else
    cout << "we're not using a kinematic fit" << endl;

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma#gamma} [GeV]",  100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);   
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 300., 1000.);
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
  char datasetnameB[700];
  if(!opts.getBoolVal("kinfit")) {
    sprintf(datasetnameB, "/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_senzaKF_senzaMassCuts/Radion_diphojet_sherpa_8TeV_default_CSV.root");  
  } else {   
    sprintf(datasetnameB, "/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_conKF_senzaMassCuts/Radion_diphojet_sherpa_8TeV_default_CSV.root");    
  }
  
  char treename[300];
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
    
    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closure_LS_mc.config");     
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closure_SR.config");    
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_LS.config");     
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_SR.config");    
    }

  } else {

    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closure_LS.config");    
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closure_SR.config");    
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_LS.config");    
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_SR.config");    
    }
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
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_closure_cat2.pdf");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_closure_cat2.pdf");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_closure_cat2.pdf");     

  } else if (category==1) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_closure_cat1.png");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_closure_cat1.png");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_closure_cat1.png");     
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_closure_cat1.pdf");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_closure_cat1.pdf");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_closure_cat1.pdf");     

  } else if (category==0) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_closure_cat0.png");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_closure_cat0.png");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_closure_cat0.png");     
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_closure_cat0.pdf");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_closure_cat0.pdf");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_closure_cat0.pdf");     
  }
  c->SaveAs(plotfilename);
}


//////////////////////////////////////////////////////////////////////////////////////////////////

void PlotGGPerAlphaData(int region, int category, int nbins) {   

  cout << "Plot the fit results to data. The region is " << region << ", the btag category is " << category << endl;

  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // w/wo kinematic fit                                                                                                 
  if(opts.getBoolVal("kinfit"))
    cout << "we're using a kinematic fit"     << endl;
  else
    cout << "we're not using a kinematic fit" << endl;

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma#gamma} [GeV]", 100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",       50., 250.);   
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 300., 1000.);
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
  char datasetnameB[700];
  if(!opts.getBoolVal("kinfit"))
    sprintf(datasetnameB, "/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_senzaKF_senzaMassCuts/Radion_Data_default_CSV.root");   
  else 
    sprintf(datasetnameB, "/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07_senzaRegression_conKF_senzaMassCuts/Radion_Data_default_CSV.root");
      
  char treename[300];
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

    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closure_LS.config");     
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closure_SR.config");    
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_LS.config");     
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closure_SR.config");    
    }

  } else {

    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closure_LS.config");    
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closure_SR.config");    
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_LS.config");    
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closure_SR.config");    
    }

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
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_closure_cat2.pdf");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_closure_cat2.pdf");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_closure_cat2.pdf");     

  } else if (category==1) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_closure_cat1.png");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_closure_cat1.png");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_closure_cat1.png");     
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_closure_cat1.pdf");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_closure_cat1.pdf");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_closure_cat1.pdf");     

  } else if (category==0) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_closure_cat0.png");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_closure_cat0.png");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_closure_cat0.png");     
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_closure_cat0.pdf");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_closure_cat0.pdf");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_closure_cat0.pdf");     
  }
  c->SaveAs(plotfilename);
}


//////////////////////////////////////////////////////////////////////////////////////////////////

// files non aggiornati per usare l'ultima versione senza regression e con subleading gamma running pT cut
void PlotGGPerAlphaCS(int region, int category, int nbins) {   

  cout << "Plot the fit results to data in CIC CS. The region is " << region << ", the btag category is " << category << endl;

  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // w/wo kinematic fit                                                                                                     
  if(opts.getBoolVal("kinfit"))
    cout << "we're using a kinematic fit"     << endl;
  else
    cout << "we're not using a kinematic fit" << endl;

  // define the structure of the dataset
  RooRealVar* massggnewvtx = new RooRealVar("massggnewvtx", "m_{#gamma#gamma} [GeV]",  100., 180.);
  RooRealVar* mjj          = new RooRealVar("mjj",          "m_{jet jet} [GeV]",        50., 250.);   
  RooRealVar* mggjj;
  if(opts.getBoolVal("lowMass"))
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 200., 700.);
  else
    mggjj = new RooRealVar("mggjj", "m_{#gamma#gamma jet jet} [GeV]", 300., 1000.);
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
  char datasetnameB[700];
  if(!opts.getBoolVal("kinfit")) 
    sprintf(datasetnameB, "/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_senzaMassCuts__CS/Radion_Data_default_CSV__withWeightsForSidebands.root");
  else
    sprintf(datasetnameB, "/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_conKinFit_senzaMassCuts__CS/Radion_Data_default_CSV__withWeightsForSidebands.root");

  char treename[300];
  sprintf(treename,"myTrees_withWeight");   

  RooDataSet *data = getDataSetCS(datasetnameB,  treename);

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

    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closureCS_LS.config");     
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closureCS_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_closureCS_SR.config");    
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closureCS_LS.config");     
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closureCS_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_closureCS_SR.config");    
    }

  } else {

    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closureCS_LS.config");    
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closureCS_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_closureCS_SR.config");    
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closureCS_LS.config");    
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closureCS_HS.config");    
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_closureCS_SR.config");    
    }
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
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataCSPlot_lowSideband_closure_cat2.png");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataCSPlot_highSideband_closure_cat2.png");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataCSPlot_signalRegion_closure_cat2.png");     
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataCSPlot_lowSideband_closure_cat2.pdf");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataCSPlot_highSideband_closure_cat2.pdf");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataCSPlot_signalRegion_closure_cat2.pdf");     

  } else if (category==1) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataCSPlot_lowSideband_closure_cat1.png");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataCSPlot_highSideband_closure_cat1.png");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataCSPlot_signalRegion_closure_cat1.png");     
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataCSPlot_lowSideband_closure_cat1.pdf");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataCSPlot_highSideband_closure_cat1.pdf");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataCSPlot_signalRegion_closure_cat1.pdf");     

  } else if (category==0) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataCSPlot_lowSideband_closure_cat0.png");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataCSPlot_highSideband_closure_cat0.png");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataCSPlot_signalRegion_closure_cat0.png");     
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataCSPlot_lowSideband_closure_cat0.pdf");     
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataCSPlot_highSideband_closure_cat0.pdf");     
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataCSPlot_signalRegion_closure_cat0.pdf");     
  }
  c->SaveAs(plotfilename);
}
