
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

// in uso
void FitGGPerAlphaMC(int region, int category);   
void FitGGPerAlphaData(int region, int category);   

void PlotGGPerAlphaMC(int region, int category, int nbins);   
void PlotGGPerAlphaData(int region, int category, int nbins);

void PlotGGPerAlpha_writeCorrectedWS_lowMass_meth2(int category);    

// not to be used for the moment (CS files still not up to date)
void FitGGPerAlphaCS(int region, int category);
void PlotGGPerAlphaCS(int region, int category, int nbins);
void PlotGGPerAlpha_writeCorrectedWS_lowMass_meth2FromCS(int category);    

// not used any more
// void PlotGGPerAlpha_writeCorrectedWS_highMass(int category);    



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


  /* questo non serve
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


  /* questo non serve
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

  /*  chiara: non to be used for the moments, files still not updated
  cout << "Fit to data CS:  low sideband - no categorization"  << endl; 
  FitGGPerAlphaCS(0,2);
  cout << "Fit to data CS:  high sideband - no categorization" << endl; 
  FitGGPerAlphaCS(1,2);
  cout << "Fit to data CS:  signal region - no categorization" << endl; 
  FitGGPerAlphaCS(2,2);
  cout << endl;

  cout << "Check fit to data CS:  low sideband - no categorization"  << endl;
  PlotGGPerAlphaCS(0,2,19);
  cout << "Check fit to data CS:  high sideband - no categorization" << endl;
  PlotGGPerAlphaCS(1,2,19);
  cout << "Check fit to data CS:  signal region - no categorization" << endl;
  PlotGGPerAlphaCS(2,2,19);
  cout << endl;
  */

  /* chiara: non to be used for the moments, files still not updated
  cout << "Fit to data CS:  low sideband - btag category=1"  << endl; 
  FitGGPerAlphaCS(0,1);
  cout << "Fit to data CS:  high sideband - btag category=1" << endl; 
  FitGGPerAlphaCS(1,1);
  cout << "Fit to data CS:  signal region - btag category=1" << endl; 
  FitGGPerAlphaCS(2,1);
  cout << endl;

  cout << "Check fit to data CS:  low sideband - btag category=1"  << endl;                                                  
  PlotGGPerAlphaCS(0,1,19); 
  cout << "Check fit to data CS:  high sideband - btag category=1" << endl;
  PlotGGPerAlphaCS(1,1,19);
  cout << "Check fit to data CS:  signal region - btag category=1" << endl; 
  PlotGGPerAlphaCS(2,1,19);
  cout << endl;
  */

  /* chiara: non to be used for the moments, files still not updated
  cout << "Fit to data CS:  low sideband - btag category=2"  << endl; 
  FitGGPerAlphaCS(0,0);
  cout << "Fit to data CS:  high sideband - btag category=2" << endl; 
  FitGGPerAlphaCS(1,0);
  cout << "Fit to data CS:  signal region - btag category=2" << endl; 
  FitGGPerAlphaCS(2,0);
  cout << endl;

  cout << "Check fit to data CS:  low sideband - btag category=2"  << endl; 
  PlotGGPerAlphaCS(0,0,19);  
  cout << "Check fit to data CS:  high sideband - btag category=2" << endl;
  PlotGGPerAlphaCS(1,0,19);                                         
  cout << "Check fit to data CS:  signal region - btag category=2" << endl;
  PlotGGPerAlphaCS(2,0,19); 
  cout << endl;
  */

  cout << endl;

  cout << endl;
  cout << "Preparing new workspace for background" << endl;
  if(opts.getBoolVal("lowMass")) {
    PlotGGPerAlpha_writeCorrectedWS_lowMass_meth2(2);    
    PlotGGPerAlpha_writeCorrectedWS_lowMass_meth2(1);    
    PlotGGPerAlpha_writeCorrectedWS_lowMass_meth2(0);
    //PlotGGPerAlpha_writeCorrectedWS_lowMass_meth2FromCS(2);    
    //PlotGGPerAlpha_writeCorrectedWS_lowMass_meth2FromCS(1);    
    //PlotGGPerAlpha_writeCorrectedWS_lowMass_meth2FromCS(0);
  }    
  else {
    // PlotGGPerAlpha_writeCorrectedWS_highMass(2);      
    // PlotGGPerAlpha_writeCorrectedWS_highMass(1);      
    // PlotGGPerAlpha_writeCorrectedWS_highMass(0);      
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

    sprintf(toSave,"mtotBkg_cat%d",cat);
    if(opts.getBoolVal("lowMass")) {
      RooLandau *pdfL = wsCatX->pdf(toSave);
      wAllAll->import(*pdfL);
    } else {
      RooExponential *pdfH = wsCatX->pdf(toSave);
      wAllAll->import(*pdfH);
    }

    // sprintf(toSave,"data_obs_cat%d",cat);
    // RooDataHist *dataB = wsCatX->data(toSave);

    sprintf(toSave,"Data_cat%d",cat);
    RooDataHist *dataU = wsCatX->data(toSave);

    wAllAll->import(*dataU);
    // wAllAll->import(*dataB);
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

// preparing a roodataset from the CIC CS in data - the weight is different and is hardcoded 
// chiara: not to be used because the CS files are not updated
RooDataSet *getDataSetCS(const char *rootfile, const char *treename) {

  cout << endl;
  cout << "running getDataSetCS" << endl;
  cout << endl;

  cout << "roofitting file " << rootfile << endl;
  cout << "Creating a weighted dataset, where weight is pt_scaled_2D_weight_data." << endl;

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
  RooRealVar* pt_scaled_2D_weight_data = new RooRealVar("pt_scaled_2D_weight_data", "pt_scaled_2D_weight_data", 0,10.);

  RooArgSet setall(*massggnewvtx,*mjj,*mggjj,*btagCategory,*pt_scaled_2D_weight_data);

  TFile *file = TFile::Open(rootfile);
  TTree *tree = (TTree*)file->Get(treename);

  RooDataSet *data = new RooDataSet("myTrees","dataset",tree,setall,0,pt_scaled_2D_weight_data->GetName());

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
  char datasetnameB[700];
  if(!opts.getBoolVal("kinfit")) {    
    sprintf(datasetnameB, "/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_noKF/Radion_diphojet_sherpa_8TeV_default_CSV.root");
  } else {
    sprintf(datasetnameB, "/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_siKF/Radion_diphojet_sherpa_8TeV_default_CSV.root");
  }

  char treename[300];
  sprintf(treename,"myTrees");   
  
  RooDataSet *data = getDataSet(datasetnameB,  treename, true);

  // selection 
  if(opts.getBoolVal("lowMass")) {

    if (category==2) {       
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
    
    if(opts.getBoolVal("kinfit")) {
      if (region==0)      sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_LS_mc.config");    
      else if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_HS.config");    
      else if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_SR_mc.config");    
    } else {
      if (region==0)      sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_LS.config");    
      else if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_HS.config");    
      else if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_SR.config");    
    }
    
  } else {
    
    if(opts.getBoolVal("kinfit")) {
      if (region==0)      sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_LS.config");    
      else if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_HS.config");    
      else if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_SR.config");    
    } else {
      if (region==0)      sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_LS.config");    
      else if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_HS.config");    
      else if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_SR.config");    
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
				       RooFit::SumW2Error(kFALSE));   // chiara, secondo me cosi'
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////

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
  char datasetnameB[700];
  if(!opts.getBoolVal("kinfit"))
    sprintf(datasetnameB, "/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_noKF/Radion_Data_default_CSV.root");
  else
    sprintf(datasetnameB, "/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_siKF/Radion_Data_default_CSV.root");

  char treename[300];
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

    if(opts.getBoolVal("kinfit")) {
      if (region==0)      sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_LS.config");    
      else if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_HS.config");    
      else if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_SR.config");    
    } else {
      if (region==0)      sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_LS.config");    
      else if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_HS.config");    
      else if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_SR.config");    
    }

  } else {
    
    if(opts.getBoolVal("kinfit")) {
      if (region==0)      sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_LS.config");    
      else if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_HS.config");    
      else if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_SR.config");    
    } else {
      if (region==0)      sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_LS.config");    
      else if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_HS.config");    
      else if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_SR.config");    
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// chiara: still not to be used because the files are not updated 
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

    if(!opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_CS_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_CS_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_CS_SR.config");
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_CS_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_CS_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_CS_SR.config");
    }

  } else {

    if(!opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_CS_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_CS_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_CS_SR.config");
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_CS_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_CS_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_CS_SR.config");
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
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat2_dataCS.config");
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat2_dataCS.config");
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat2_dataCS.config");

  } else if (category==1) {
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat1_dataCS.config");
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat1_dataCS.config");
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat1_dataCS.config");

  } else if (category==0) {
    if (region==0)      theFit.writeConfigFile("fitres/fitBackground_lowSideband_cat0_dataCS.config");
    else if (region==1) theFit.writeConfigFile("fitres/fitBackground_highSideband_cat0_dataCS.config");
    else if (region==2) theFit.writeConfigFile("fitres/fitBackground_signalRegion_cat0_dataCS.config");
  }

  TFile *fileOut;
  if (category==2) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat2_dataCS.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat2_dataCS.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat2_dataCS.root","RECREATE");

  } else if (category==1) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat1_dataCS.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat1_dataCS.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat1_dataCS.root","RECREATE");

  } else if (category==0) {
    if      (region==0)  fileOut = new TFile("fitres/fitRes_region0_cat0_dataCS.root","RECREATE");
    else if (region==1)  fileOut = new TFile("fitres/fitRes_region1_cat0_dataCS.root","RECREATE");
    else if (region==2)  fileOut = new TFile("fitres/fitRes_region2_cat0_dataCS.root","RECREATE");
  }

  fileOut->cd();
  fitres->Write();
  fileOut->Close();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PlotGGPerAlpha_writeCorrectedWS_lowMass_meth2(int category) {    
  
  cout << "preparing workspace at low mass, method2, category = " << category << endl;

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
  RooPlot *plot3  = Var->frame(min,max,25);    
  RooPlot *plot4  = Var->frame(min,max,25);    

  // Now reading the previous fit results for sidebands and signal region (data and mc).
  // Generate events according to those distributions  
  RooAbsPdf *thePdfLMc, *thePdfSMc, *thePdfLData;
  RooArgSet setqui(*mggjj);

  cout << endl;
  cout << "Reading results from low sideband fit in MC" << endl;
  if (category==2)                theFit.initialize("fitres/fitBackground_lowSideband_cat2_mc.config");  
  if (category==0 || category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_mc.config");  
  thePdfLMc = theFit.getPdf("myFit");
  thePdfLMc->plotOn(plot, RooFit::LineColor(kBlue));
  RooDataSet *genMcL = thePdfLMc->generate(setqui,2000000,kTRUE,kFALSE);
  (thePdfLMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);

  cout << endl;
  cout << "Reading results from signal region fit in MC" << endl;
  if (category==2)                theFit.initialize("fitres/fitBackground_signalRegion_cat2_mc.config");  
  if (category==0 || category==1) theFit.initialize("fitres/fitBackground_signalRegion_cat1_mc.config");  
  thePdfSMc = theFit.getPdf("myFit");
  thePdfSMc->plotOn(plot, RooFit::LineColor(kRed));
  RooDataSet *genMcS = thePdfSMc->generate(setqui,2000000,kTRUE,kFALSE);
  (thePdfSMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);

  cout << endl;
  cout << "Reading results from low sideband fit in Data" << endl;
  if (category==2)                theFit.initialize("fitres/fitBackground_lowSideband_cat2_data.config");  
  if (category==0 || category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_data.config");  
  thePdfLData = theFit.getPdf("myFit");
  RooDataSet *genDataL = thePdfLData->generate(setqui,2000000,kTRUE,kFALSE);
  (thePdfLData->getParameters(setqui))->writeToStream(std::cout,kFALSE);

  // plot from the original pdfs
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

  TCanvas *myC = new TCanvas("myC","",1);
  myC->cd();
  plot->SetYTitle("Events");
  plot->Draw();
  leg->Draw();
  if      (category==2)                myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat2.png");  
  else if (category==1 || category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat1.png");  
  if      (category==2)                myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat2.pdf");  
  else if (category==1 || category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat1.pdf");  
  if      (category==2)                myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat2.root");  
  else if (category==1 || category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat1.root");  


  // Trees and histos from the previous toys  
  TTree *treeGenDataL = dataset2tree(genDataL);
  TTree *treeGenMcL   = dataset2tree(genMcL);
  TTree *treeGenMcS   = dataset2tree(genMcS);

  TH1F *h1_mggjj_genMcL, *h1_mggjj_genMcS, *h1_mggjj_genDataL;
  h1_mggjj_genMcL   = new TH1F("h1_mggjj_genMcL",  "h1_mggjj_genMcL",  50,200.,700.);
  h1_mggjj_genMcS   = new TH1F("h1_mggjj_genMcS",  "h1_mggjj_genMcS",  50,200.,700.);
  h1_mggjj_genDataL = new TH1F("h1_mggjj_genDataL","h1_mggjj_genDataL",50,200.,700.);
  h1_mggjj_genMcL->Sumw2();
  h1_mggjj_genMcS->Sumw2();
  h1_mggjj_genDataL->Sumw2();
  treeGenMcL  ->Project("h1_mggjj_genMcL",  "mggjj");
  treeGenMcS  ->Project("h1_mggjj_genMcS",  "mggjj");
  treeGenDataL->Project("h1_mggjj_genDataL","mggjj");
  
  h1_mggjj_genMcL->SetLineColor(kBlue);
  h1_mggjj_genMcS->SetLineColor(kRed);
  h1_mggjj_genDataL->SetLineColor(kBlue);
  h1_mggjj_genMcL   -> Scale(1./(h1_mggjj_genMcL->Integral()));
  h1_mggjj_genMcS   -> Scale(1./(h1_mggjj_genMcS->Integral()));
  h1_mggjj_genDataL -> Scale(1./(h1_mggjj_genDataL->Integral()));
  

  // --------------------------------------------------------------------------------------------------------
  // Now making an histogram which is the product of previous ones 
  // and which should represent the data in the signal region                                             
  // ==> this is our background estimate <==     
  TH1F *h1_resultHisto = new TH1F("h1_resultHisto", "h1_resultHisto", 50,200.,700.);
  h1_resultHisto->Sumw2();
  h1_resultHisto->Add(h1_mggjj_genMcS,1);
  h1_resultHisto->Divide(h1_mggjj_genMcL);
  h1_resultHisto->Multiply(h1_mggjj_genDataL);
  h1_resultHisto->SetFillColor(kGreen-9);

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
  if      (category==2)                myC2.SaveAs("fitres/resultHistoWithFit_cat2.png");
  else if (category==1 || category==0) myC2.SaveAs("fitres/resultHistoWithFit_cat1.png");



  // -------------------------------------------------------------------------------------------
  // this is done with very small errors, because they come from 2M events for each histo 
  // First we rescale the errors of the histos used to make the final one to be representative 
  // of the initial statistics, then we re-do the fit      
  // This is the only part which really uses 2btag events for the 2btag category

  // loading the dataset for data in low sideband       
  RooDataSet *dataL;
  if(!opts.getBoolVal("kinfit"))
    dataL = getDataSet2("/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_noKF/Radion_Data_default_CSV.root", "myTrees", category);
  else
    dataL = getDataSet2("/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_siKF/Radion_Data_default_CSV.root", "myTrees", category);

  if (category==0)
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1)
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2)
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");


  // loading the dataset for MC in low sideband 
  RooDataSet *mcL;
  if(!opts.getBoolVal("kinfit"))
    mcL = getDataSet("/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_noKF/Radion_diphojet_sherpa_8TeV_default_CSV.root", "myTrees", true);
  else
    mcL = getDataSet("/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_siKF/Radion_diphojet_sherpa_8TeV_default_CSV.root", "myTrees", true);

  if (category==0)
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1)
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2)
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");


  // loading the dataset for MC in the signal region
  RooDataSet *mcS;
  if(!opts.getBoolVal("kinfit"))
    mcS = getDataSet("/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_noKF/Radion_diphojet_sherpa_8TeV_default_CSV.root", "myTrees", true);
  else
    mcS = getDataSet("/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_siKF/Radion_diphojet_sherpa_8TeV_default_CSV.root", "myTrees", true);

  if (category==0)
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1)
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2)
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");


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


  // Now loading the data dataset (signal region) to be also saved in the workspace
  // This is the only part which really uses 2btag events for the 2btag category
  char datasetnameB[700];
  if(!opts.getBoolVal("kinfit"))
    sprintf(datasetnameB, "/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_noKF/Radion_Data_default_CSV.root");   
  else
    sprintf(datasetnameB, "/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_siKF/Radion_Data_default_CSV.root");

  char treename[300];
  sprintf(treename,"myTrees");
  RooDataSet *data = getDataSet2(datasetnameB, treename, category);

  if (category==0) 
    data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1) 
    data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2) 
    data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
  float numEntries = (float)(data->numEntries());


  // New fit after proper normalization 
  h1c_resultHisto->Scale( numEntries / (h1c_resultHisto->Integral()) );
  h1c_resultHisto->SetMinimum(0);
  h1c_resultHisto->SetMarkerStyle(20);

  // Now replacing the values from sideband fit with alpha-corrected ones
  // and preparing a new PDF to be saved in the workspace for the fit
  char nameToSave[300];
  sprintf(nameToSave,"mtot_bkg_mean_cat%d",category);
  RooRealVar meanL (nameToSave, nameToSave, 300, 200., 400.);
  sprintf(nameToSave,"mtot_bkg_sigma_cat%d",category);
  RooRealVar sigmaL(nameToSave, nameToSave, 40,  10.,  60.);    
  RooAbsPdf *landauT = new RooLandau("landauT", "landauT", *mggjj, meanL, sigmaL);  

  RooDataHist resultHistoRDH2("resultHistoRDH2", "resultHistoRDH2", *mggjj, h1c_resultHisto);
  landauT->fitTo(resultHistoRDH2, RooFit::SumW2Error(kFALSE));    // chiara: secondo me deve essere kfalse!); 
  resultHistoRDH2.plotOn(plot4, RooFit::LineColor(kBlack));
  landauT->plotOn(plot4, RooFit::LineColor(kGreen));

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

  sprintf(nameToSave,"mtotBkg_cat%d",category);
  RooAbsPdf *landau = new RooLandau(nameToSave, nameToSave, *mggjj, meanL, sigmaL);  
  sprintf(nameToSave,"mtot_bkg_mean_cat%d",category);
  float myMeanControllo   = (landau->getParameters(setqui))->getRealValue(nameToSave);
  sprintf(nameToSave,"mtot_bkg_sigma_cat%d",category);
  float mySigmaControllo  = (landau->getParameters(setqui))->getRealValue(nameToSave);
  cout << "for check - must be the same as above: " << myMeanControllo << " " << mySigmaControllo << endl;
  cout << endl;

  
  // convert it into a roodatahist - chiara: come capisco i bin?? 
  // RooArgSet setqui2(*mggjj);
  // sprintf(nameToSave,"data_obs_cat%d",category);
  // RooDataHist dataBinned(nameToSave, nameToSave, setqui2, *data);  

  // And finally saving everything in the workspace
  RooWorkspace *wAll = new RooWorkspace("w_all1cat","w_all1cat");
  wAll->import(*landau);
  // wAll->import(dataBinned);
  wAll->import(*data);

  cout << endl;
  cout << endl;
  std::cout << "done with importing background pdfs" << std::endl;
  sprintf(nameToSave,"lowMassWS_cat%d.root",category);
  wAll->writeToFile(nameToSave);

  wAll->Print();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// chiara: not to be used because files are not updated
void PlotGGPerAlpha_writeCorrectedWS_lowMass_meth2FromCS(int category) {    
  
  cout << "preparing workspace at low mass, method2, alpha from CIC CS, category = " << category << endl;

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
  RooPlot *plot3  = Var->frame(min,max,25);    
  RooPlot *plot4  = Var->frame(min,max,25);    

  // Now reading the previous fit results for sidebands and signal region (data and mc).
  // Generate events according to those distributions  
  RooAbsPdf *thePdfLMc, *thePdfSMc, *thePdfLData;
  RooArgSet setqui(*mggjj);

  cout << endl;
  cout << "Reading results from low sideband fit to data CS" << endl;
  if (category==2)                theFit.initialize("fitres/fitBackground_lowSideband_cat2_dataCS.config");  
  if (category==0 || category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_dataCS.config");  
  thePdfLMc = theFit.getPdf("myFit");
  thePdfLMc->plotOn(plot, RooFit::LineColor(kBlue));
  RooDataSet *genMcL = thePdfLMc->generate(setqui,2000000,kTRUE,kFALSE);
  (thePdfLMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);

  cout << endl;
  cout << "Reading results from signal region fit to data CS" << endl;
  if (category==2)                theFit.initialize("fitres/fitBackground_signalRegion_cat2_dataCS.config");  
  if (category==0 || category==1) theFit.initialize("fitres/fitBackground_signalRegion_cat1_dataCS.config");  
  thePdfSMc = theFit.getPdf("myFit");
  thePdfSMc->plotOn(plot, RooFit::LineColor(kRed));
  RooDataSet *genMcS = thePdfSMc->generate(setqui,2000000,kTRUE,kFALSE);
  (thePdfSMc->getParameters(setqui))->writeToStream(std::cout,kFALSE);

  cout << endl;
  cout << "Reading results from low sideband fit in Data" << endl;
  if (category==2)                theFit.initialize("fitres/fitBackground_lowSideband_cat2_data.config");  
  if (category==0 || category==1) theFit.initialize("fitres/fitBackground_lowSideband_cat1_data.config");  
  thePdfLData = theFit.getPdf("myFit");
  RooDataSet *genDataL = thePdfLData->generate(setqui,2000000,kTRUE,kFALSE);
  (thePdfLData->getParameters(setqui))->writeToStream(std::cout,kFALSE);

  // plot from the original pdfs
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

  TCanvas *myC = new TCanvas("myC","",1);
  myC->cd();
  plot->SetYTitle("Events");
  plot->Draw();
  leg->Draw();
  if      (category==2)                myC->SaveAs("fitres/mGGJJ_pdfFittedToDataCS_cat2.png");  
  else if (category==1 || category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToDataCS_cat1.png");  
  if      (category==2)                myC->SaveAs("fitres/mGGJJ_pdfFittedToDataCS_cat2.root");  
  else if (category==1 || category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToDataCS_cat1.root");  


  // Trees and histos from the previous toys  
  TTree *treeGenDataL = dataset2tree(genDataL);
  TTree *treeGenMcL   = dataset2tree(genMcL);
  TTree *treeGenMcS   = dataset2tree(genMcS);

  TH1F *h1_mggjj_genMcL, *h1_mggjj_genMcS, *h1_mggjj_genDataL;
  h1_mggjj_genMcL   = new TH1F("h1_mggjj_genMcL",  "h1_mggjj_genMcL",  50,200.,700.);
  h1_mggjj_genMcS   = new TH1F("h1_mggjj_genMcS",  "h1_mggjj_genMcS",  50,200.,700.);
  h1_mggjj_genDataL = new TH1F("h1_mggjj_genDataL","h1_mggjj_genDataL",50,200.,700.);
  h1_mggjj_genMcL->Sumw2();
  h1_mggjj_genMcS->Sumw2();
  h1_mggjj_genDataL->Sumw2();
  treeGenMcL  ->Project("h1_mggjj_genMcL",  "mggjj");
  treeGenMcS  ->Project("h1_mggjj_genMcS",  "mggjj");
  treeGenDataL->Project("h1_mggjj_genDataL","mggjj");
  
  h1_mggjj_genMcL->SetLineColor(kBlue);
  h1_mggjj_genMcS->SetLineColor(kRed);
  h1_mggjj_genDataL->SetLineColor(kBlue);
  h1_mggjj_genMcL   -> Scale(1./(h1_mggjj_genMcL->Integral()));
  h1_mggjj_genMcS   -> Scale(1./(h1_mggjj_genMcS->Integral()));
  h1_mggjj_genDataL -> Scale(1./(h1_mggjj_genDataL->Integral()));
  

  // --------------------------------------------------------------------------------------------------------
  // Now making an histogram which is the product of previous ones 
  // and which should represent the data in the signal region                                             
  // ==> this is our background estimate <==     
  TH1F *h1_resultHisto = new TH1F("h1_resultHisto", "h1_resultHisto", 50,200.,700.);
  h1_resultHisto->Sumw2();
  h1_resultHisto->Add(h1_mggjj_genMcS,1);
  h1_resultHisto->Divide(h1_mggjj_genMcL);
  h1_resultHisto->Multiply(h1_mggjj_genDataL);
  h1_resultHisto->SetFillColor(kGreen-9);

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
  if      (category==2)                myC2.SaveAs("fitres/resultHistoWithFit_cat2.png");
  else if (category==1 || category==0) myC2.SaveAs("fitres/resultHistoWithFit_cat1.png");



  // -------------------------------------------------------------------------------------------
  // this is done with very small errors, because they come from 2M events for each histo 
  // First we rescale the errors of the histos used to make the final one to be representative 
  // of the initial statistics, then we re-do the fit      
  // This is the only part which really uses 2btag events for the 2btag category

  // loading the dataset for data in low sideband       
  RooDataSet *dataL;
  if(!opts.getBoolVal("kinfit"))
    dataL = getDataSet2("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_noKF/Radion_Data_default_CSV.root", "myTrees", category);
  else
    dataL = getDataSet2("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_siKF/Radion_Data_default_CSV.root", "myTrees", category);

  if (category==0)
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1)
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2)
    dataL = (RooDataSet*)dataL->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");


  // loading the dataset for CIC CS in low sideband 
  RooDataSet *mcL;
  if(!opts.getBoolVal("kinfit"))
    mcL = getDataSetCS("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_senzaMassCuts__CS/Radion_Data_default_CSV__withWeightsForSidebands.root", "myTrees_withWeight");
  else
    mcL = getDataSetCS("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_conKinFit_senzaMassCuts__CS/Radion_Data_default_CSV__withWeightsForSidebands.root", "myTrees_withWeight");

  if (category==0)
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1)
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2)
    mcL = (RooDataSet*)mcL->reduce("massggnewvtx>100 && massggnewvtx<=120 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");


  // loading the dataset for MC in the signal region
  RooDataSet *mcS;
  if(!opts.getBoolVal("kinfit"))
    mcS = getDataSetCS("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_senzaMassCuts__CS/Radion_Data_default_CSV__withWeightsForSidebands.root", "myTrees_withWeight");
  else
    mcS = getDataSetCS("/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V07__senzaUsareBtag_conRegression_conKinFit_senzaMassCuts__CS/Radion_Data_default_CSV__withWeightsForSidebands.root", "myTrees_withWeight");

  if (category==0)
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1)
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2)
    mcS = (RooDataSet*)mcS->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");


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


  // Now loading the data dataset (signal region) to be also saved in the workspace
  // This is the only part which really uses 2btag events for the 2btag category
  char datasetnameB[700];
  if(!opts.getBoolVal("kinfit"))
    sprintf(datasetnameB, "/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_noKF/Radion_Data_default_CSV.root");
  else
    sprintf(datasetnameB, "/afs/cern.ch/user/c/crovelli/myWorkspace/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_siKF/Radion_Data_default_CSV.root");
  
  char treename[300];
  sprintf(treename,"myTrees");
  RooDataSet *data = getDataSet2(datasetnameB, treename, category);

  if (category==0) 
    data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==2");
  else if (category==1) 
    data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200 && btagCategory==1");
  else if (category==2) 
    data = (RooDataSet*)data->reduce("massggnewvtx>120 && massggnewvtx<=130 && mjj>90 && mjj<170 && mggjj<700 && mggjj>200");
  float numEntries = (float)(data->numEntries());


  // New fit after proper normalization 
  h1c_resultHisto->Scale( numEntries / (h1c_resultHisto->Integral()) );
  h1c_resultHisto->SetMinimum(0);
  h1c_resultHisto->SetMarkerStyle(20);

  // Now replacing the values from sideband fit with alpha-corrected ones
  // and preparing a new PDF to be saved in the workspace for the fit
  char nameToSave[300];
  sprintf(nameToSave,"mtot_bkg_mean_cat%d",category);
  RooRealVar meanL (nameToSave, nameToSave, 300, 200., 400.);
  sprintf(nameToSave,"mtot_bkg_sigma_cat%d",category);
  RooRealVar sigmaL(nameToSave, nameToSave, 40,  20.,  60.);
  RooAbsPdf *landauT = new RooLandau("landauT", "landauT", *mggjj, meanL, sigmaL);  

  RooDataHist resultHistoRDH2("resultHistoRDH2", "resultHistoRDH2", *mggjj, h1c_resultHisto);
  landauT->fitTo(resultHistoRDH2, RooFit::SumW2Error(kFALSE));    // chiara: secondo me deve essere kfalse!); 
  resultHistoRDH2.plotOn(plot4, RooFit::LineColor(kBlack));
  landauT->plotOn(plot4, RooFit::LineColor(kGreen));

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

  sprintf(nameToSave,"mtotBkg_cat%d",category);
  RooAbsPdf *landau = new RooLandau(nameToSave, nameToSave, *mggjj, meanL, sigmaL);  
  sprintf(nameToSave,"mtot_bkg_mean_cat%d",category);
  float myMeanControllo   = (landau->getParameters(setqui))->getRealValue(nameToSave);
  sprintf(nameToSave,"mtot_bkg_sigma_cat%d",category);
  float mySigmaControllo  = (landau->getParameters(setqui))->getRealValue(nameToSave);
  cout << "for check - must be the same as above: " << myMeanControllo << " " << mySigmaControllo << endl;
  cout << endl;
  
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
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// not used anymore
/*
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
  if      (category==2) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat2.pdf");  
  else if (category==1) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat1.pdf");  
  else if (category==0) myC->SaveAs("fitres/mGGJJ_pdfFittedToMc_cat0.pdf");  

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
  sprintf(nameToSave,"mtot_bkg_exp_cat%d",category);
  RooRealVar exp (nameToSave, nameToSave, ePars[0], ePars[1], ePars[2]);
  exp.setConstant(kTRUE);
  
  sprintf(nameToSave,"mtotBkg_cat%d",category);
  RooAbsPdf *exponential = new RooExponential(nameToSave, nameToSave, *mggjj, exp);
  sprintf(nameToSave,"mtot_bkg_exp_cat%d",category);
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
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
  char datasetnameB[700];
  if(!opts.getBoolVal("kinfit")) {
    sprintf(datasetnameB, "/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_noKF/Radion_diphojet_sherpa_8TeV_default_CSV.root");
  } else {
    sprintf(datasetnameB, "/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_siKF/Radion_diphojet_sherpa_8TeV_default_CSV.root");
  }

  char treename[300];
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

    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_LS_mc.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_SR_mc.config");
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_SR.config");
    }

  } else {

    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_SR.config");
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_SR.config");
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
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_cat2.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_cat2.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_cat2.png");
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_cat2.pdf");
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_cat2.pdf");
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_cat2.pdf");

  } else if (category==1) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_cat1.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_cat1.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_cat1.png");
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_cat1.pdf");
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_cat1.pdf");
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_cat1.pdf");

  } else if (category==0) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_cat0.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_cat0.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_cat0.png");
    if (region==0)      sprintf(plotfilename,"fitres/fitToMcPlot_lowSideband_cat0.pdf");
    else if (region==1) sprintf(plotfilename,"fitres/fitToMcPlot_highSideband_cat0.pdf");
    else if (region==2) sprintf(plotfilename,"fitres/fitToMcPlot_signalRegion_cat0.pdf");
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
  char datasetnameB[700];
  if(!opts.getBoolVal("kinfit"))
    sprintf(datasetnameB, "/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_noKF/Radion_Data_default_CSV.root");
  else
    sprintf(datasetnameB, "/afs/cern.ch/work/c/crovelli/Radion/CMSSW_5_3_6/src/HHggbb/finalizedTrees_Radion_V08b_perSidebands_siKF/Radion_Data_default_CSV.root");

  char treename[300];
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
    
    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_SR.config");
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_SR.config");
    }

  } else {

    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_SR.config");
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_SR.config");
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
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_cat2.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_cat2.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_cat2.png");
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_cat2.pdf");
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_cat2.pdf");
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_cat2.pdf");

  } else if (category==1) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_cat1.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_cat1.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_cat1.png");
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_cat1.pdf");
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_cat1.pdf");
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_cat1.pdf");

  } else if (category==0) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_cat0.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_cat0.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_cat0.png");
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataPlot_lowSideband_cat0.pdf");
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataPlot_highSideband_cat0.pdf");
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataPlot_signalRegion_cat0.pdf");
  }
  c->SaveAs(plotfilename);
}

//////////////////////////////////////////////////////////////////////////////////////////////////          
// chiara: still not to be used because the files are not updated
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

    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_CS_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_CS_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMassKF_CS_SR.config");
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_CS_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_CS_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyLowMass_CS_SR.config");
    }

  } else {

    if(opts.getBoolVal("kinfit")) {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_CS_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_CS_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMassKF_CS_SR.config");
    } else {
      if (region==0) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_CS_LS.config");
      if (region==1) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_CS_HS.config");
      if (region==2) sprintf(fitconfig,"fitconfig/fitBackgroundOnlyHighMass_CS_SR.config");
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
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataCSPlot_lowSideband_cat2.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataCSPlot_highSideband_cat2.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataCSPlot_signalRegion_cat2.png");

  } else if (category==1) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataCSPlot_lowSideband_cat1.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataCSPlot_highSideband_cat1.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataCSPlot_signalRegion_cat1.png");

  } else if (category==0) {
    if (region==0)      sprintf(plotfilename,"fitres/fitToDataCSPlot_lowSideband_cat0.png");
    else if (region==1) sprintf(plotfilename,"fitres/fitToDataCSPlot_highSideband_cat0.png");
    else if (region==2) sprintf(plotfilename,"fitres/fitToDataCSPlot_signalRegion_cat0.png");
  }
  c->SaveAs(plotfilename);
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
