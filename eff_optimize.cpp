{
	gROOT->SetStyle("Plain");//"Pub","Plain"
	gStyle->SetOptStat(0);//To display the mean and RMS: SetOptStat("mr"), nemruoi, ;
	gStyle->SetOptDate(1);//display date position
	/*	gStyle->SetFuncWidth(2);
		gStyle->SetFuncColor(2);
		gStyle->SetFrameBorderMode(0);
		gStyle->SetOptTitle(0);
		gStyle->SetOptFile(3);
		gStyle->SetStatFormat("5.4f");
		gStyle->SetStatStyle(3);
		gStyle->SetStatColor(kRed);
		gStyle->SetStatFont(42);//word font
		gStyle->SetTextFont(42);
		gStyle->SetStatFontSize(0.03);
		gStyle->SetStatBorderSize(3);//shadow width of border out line
		gStyle->SetStatTextColor(1);
		gStyle->SetStatH(0.15);
		gStyle->SetStatW(0.30);//Right Side Title Width
	//gStyle->SetStatX(0.845);//Margin Box Position
	//gStyle->SetStatY(0.845);
	gStyle->SetOptTitle(1);
	gStyle->SetPalette(1);
	gStyle->SetLegendBorderSize(0);
	//gStyle->SetTitleSize(0.05,"xyz");//Axis title Size
	//gStyle->SetPadTopMargin(0.15);
	//gStyle->SetPadBottomMargin(0.13);
	//gStyle->SetPadLeftMargin(0.16);
	//gStyle->SetPadRightMargin(0.12);

	gStyle->SetAxisColor(1,"XYZ");
	gStyle->SetStripDecimals(kTRUE);
	gStyle->SetTickLength(0.03,"XYZ");
	gStyle->SetOptLogx(0);//set of center of Log*/
	//---------------------------------------------------

	TLatex lt1;
	lt1.SetTextAlign(12);
	lt1.SetNDC();
	lt1.SetTextFont(132);
	lt1.SetTextAngle(0);
	lt1.SetTextSize(0.045);

	TLatex lt2;
	lt2.SetTextAlign(12);
	lt2.SetNDC();
	lt2.SetTextFont(62);
	lt2.SetTextAngle(0);
	lt2.SetTextSize(0.058);

	TLatex lt3;
	lt3.SetTextAlign(12);
	lt3.SetNDC();
	lt3.SetTextAngle(0);
	lt3.SetTextFont(52);
	lt3.SetTextSize(0.045);

	TLatex lt4;
	lt4.SetTextAlign(32);
	lt4.SetNDC();
	lt4.SetTextAngle(0);
	lt4.SetTextFont(42);
	lt4.SetTextSize(0.05);
	//----------------------------------------------------


	//--------------------------------------------------------------------------------------------------------------------

	//-----------------------------------Coordinate of CMS Simulation------------------------------------------------------------
	float x_1 = 0.1; //right top side x_1 = 0.73
	const float y_1 = 0.94; //right top side y_1 = 0.84
	float x_2 = x_1+0.095; //right top side y_2 = y_1-0.07
	float y_2 = y_1-0.005;
	//------------------------------------Coordinate of first LatexBox---------------------------------------
	float xx_1 = 0.15;
	float yy_1 = 0.80;
	//--------------------------------------Set Maximum histo---------------------------------
	//float ymin_1 = 0;
	//-----------------------------------------ExtraText---------------------------------------
	float tx = 0.9;
	float ty = 0.94;
	//-------------------------Legend coordinate--------------------
	float lx1 = 0.55;
	float ly1 = 0.30;
	float lx2 = 0.84;
	float ly2 = 0.55;
	const int IDCut = 2;//0 = Tight, 1 = Loose
	const int ISOCut = 2;//0 = TrkIso, 1 = PFIso

	TH1F *histo_Sig1[ISOCut][IDCut];
	TH1F *histo_Sig2[ISOCut][IDCut];
	TH1F *histo_Sig3[ISOCut][IDCut];
	TH1F *histo_Sig4[ISOCut][IDCut];
	TH1F *histo_Sig5[ISOCut][IDCut];
	TH1F *histo_Sig6[ISOCut][IDCut];

	TH1F *histo_Back1[ISOCut][IDCut];
	TH1F *histo_Back2[ISOCut][IDCut];
	TH1F *histo_Back3[ISOCut][IDCut];
	TH1F *histo_Back4[ISOCut][IDCut];
	TH1F *histo_Back5[ISOCut][IDCut];
	TH1F *histo_Back6[ISOCut][IDCut];

	TH1F *histo_Eff1[ISOCut][IDCut];
	TH1F *histo_Eff2[ISOCut][IDCut];
	TH1F *histo_Eff3[ISOCut][IDCut];
	TH1F *histo_Eff4[ISOCut][IDCut];
	TH1F *histo_Eff5[ISOCut][IDCut];
	TH1F *histo_Eff6[ISOCut][IDCut];

	TCanvas *canvIso_[ISOCut][IDCut];
	TLegend *l_[ISOCut][IDCut];

	int pt = 15;
	float eta = 2.4;
	int hEff_pt[]={pt,pt};//pt
	float hEff_eta[]={eta,eta};//eta

	TString PATH_samples_ZMM14TeV;
	//PATH_samples_ZMM14TeV = "/cms/scratch/quark2930/Work/muon_upgrade/samples/";//KISTI
	PATH_samples_ZMM14TeV = "/d3/scratch/yonghojeong57/CMSSW_9_0_0_pre4/src/MuonPerformance/MuonAnalyser/test/";//KNU
	//PATH_samples_ZMM14TeV = "/pnfs/user/yonghojeong57/CMSSW_9_0_0_pre4/src/MuonPerformance/MuonAnalyser/test/";//UOS
	//PATH_samples_ZMM14TeV = "/afs/cern.ch/work/y/yjeong/CMSSW_9_0_0_pre4/src/MuonPerformance/MuonAnalyser/test/";//CERN

	TString Cut_base;
	TString Signal_Trk_Tight_Cut, Signal_Trk_Loose_Cut;
	TString Signal_PF_Tight_Cut, Signal_PF_Loose_Cut;
	TString Signal_PF_Tight_Cut140, Signal_PF_Loose_Cut140;
	TString Signal_PF_Tight_Cut200, Signal_Trk_Loose_Cut200;

	TString Trk_Tight_Cut, Trk_Loose_Cut;
	TString PF_Tight_Cut, PF_Loose_Cut;
	TString PF_Tight_Cut140, PF_Loose_Cut140;
	TString PF_Tight_Cut200, PF_Loose_Cut200;

	TString LatexCutSymbol_Tight;
	TString LatexCutSymbol_Loose;

	Cut_base = "fabs(recoMuon.Pt())>15 && fabs(recoMuon.Eta())<2.4 &&";
	Trk_Tight_Cut = Cut_base+Form("recoMuon_isTight==1 && recoMuon_TrkIsolation03 < 0.5");
	Trk_Loose_Cut = Cut_base+Form("recoMuon_isLoose==1 && recoMuon_TrkIsolation03 < 1.0");
	PF_Tight_Cut = Cut_base+Form("recoMuon_isTight==1 && recoMuon_PFIsolation04 < 0.164");
	PF_Loose_Cut = Cut_base+Form("recoMuon_isLoose==1 && recoMuon_PFIsolation04 < 0.328");
	PF_Tight_Cut140 = Cut_base+Form("recoMuon_isTight==1 && recoMuon_PFIsolation04 < 0.732");
	PF_Loose_Cut140 = Cut_base+Form("recoMuon_isLoose==1 && recoMuon_PFIsolation04 < 1.012");
	PF_Tight_Cut200 = Cut_base+Form("recoMuon_isTight==1 && recoMuon_PFIsolation04 < 0.94");
	PF_Loose_Cut200 = Cut_base+Form("recoMuon_isLoose==1 && recoMuon_PFIsolation04 < 1.268");

	Signal_Trk_Tight_Cut = Trk_Tight_Cut+Form("&& recoMuon_signal==1");
	Signal_Trk_Loose_Cut = Trk_Loose_Cut+Form("&& recoMuon_signal==1");
	Signal_PF_Tight_Cut = PF_Loose_Cut+Form("&& recoMuon_signal==1");
	Signal_PF_Loose_Cut = PF_Tight_Cut+Form("&& recoMuon_signal==1");
	Signal_PF_Tight_Cut140 = PF_Loose_Cut140+Form("&& recoMuon_signal==1");
	Signal_PF_Loose_Cut140 = PF_Tight_Cut140+Form("&& recoMuon_signal==1");
	Signal_PF_Tight_Cut200 = PF_Loose_Cut200+Form("&& recoMuon_signal==1");
	Signal_PF_Loose_Cut200 = PF_Tight_Cut200+Form("&& recoMuon_signal==1");

	LatexCutSymbol_Tight = "Z/#gamma* #rightarrow#font[12]{#mu#mu} , P_{t} > 15 GeV, Tight #mu, |#eta| < 2.4, ";
	LatexCutSymbol_Loose = "Z/#gamma* #rightarrow#font[12]{#mu#mu} , P_{t} > 15 GeV, Loose #mu, |#eta| < 2.4, ";

	TFile h1(PATH_samples_ZMM14TeV+"run_ZMM_PU0_pre4_rereco02_ver01.root");
	TFile h2(PATH_samples_ZMM14TeV+"run_ZMM_PU140_pre4_rereco02_ver01.root");
	TFile h3(PATH_samples_ZMM14TeV+"run_ZMM_PU200_pre4_rereco02_ver01.root");
	TFile h4(PATH_samples_ZMM14TeV+"run_QCD_PU0_pre4_rereco02_ver01.root");
	TFile h5(PATH_samples_ZMM14TeV+"run_QCD_PU140_pre4_rereco02_ver01.root");
	TFile h6(PATH_samples_ZMM14TeV+"run_QCD_PU200_pre4_rereco02_ver01.root");

	TTree *recottree = (TTree*)h1.Get("MuonAnalyser/reco");
	TTree *recottree_140 = (TTree*)h2.Get("MuonAnalyser/reco");
	TTree *recottree_200 = (TTree*)h3.Get("MuonAnalyser/reco");
	TTree *recottree_QCD = (TTree*)h4.Get("MuonAnalyser/reco");
	TTree *recottree_QCD140 = (TTree*)h5.Get("MuonAnalyser/reco");
	TTree *recottree_QCD200 = (TTree*)h6.Get("MuonAnalyser/reco");

	for(int Iso=0; Iso<ISOCut; Iso++){
		for(int ID=0; ID<IDCut; ID++){
			float nbin_eff = 10;
			float xmin_eff = 0;
			float xmax_eff = 120;
			float ymax_eff = 1.4;
			//float ymin_eff = 0;
			float size = 0.8;
			canvIso_[Iso][ID] = new TCanvas();
			//canvIso_[Iso][ID]->SetLogy();
			canvIso_[Iso][ID]->SetFillColor(0);
			canvIso_[Iso][ID]->SetBorderMode(2);
			canvIso_[Iso][ID]->SetFrameFillStyle(3);
			canvIso_[Iso][ID]->SetFrameBorderMode(0);
			canvIso_[Iso][ID]->SetTickx(1);
			canvIso_[Iso][ID]->SetTicky(1);
			canvIso_[Iso][ID]->Update();
			canvIso_[Iso][ID]->RedrawAxis();
			canvIso_[Iso][ID]->GetFrame()->Draw();

			l_[Iso][ID] = new TLegend(lx1,ly1,lx2,ly2);
			l_[Iso][ID]->SetFillColor(0);
			l_[Iso][ID]->SetLineColor(0);
			l_[Iso][ID]->SetLineStyle(kSolid);
			l_[Iso][ID]->SetLineWidth(1);
			l_[Iso][ID]->SetFillStyle(1);
			l_[Iso][ID]->SetTextFont(2);
			l_[Iso][ID]->SetTextSize(0.035);

			histo_Sig1[Iso][ID] = new TH1F(Form("histo_Sig1%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Sig1[Iso][ID]->Sumw2();

			if(Iso==0 && ID==0  )recottree->Project(Form("histo_Sig1%d_%d",Iso,ID),"recoMuon.Pt()",Signal_Trk_Tight_Cut);
			if(Iso==0 && ID==1  )recottree->Project(Form("histo_Sig1%d_%d",Iso,ID),"recoMuon.Pt()",Signal_Trk_Loose_Cut);
			if(Iso==1 && ID==0  )recottree->Project(Form("histo_Sig1%d_%d",Iso,ID),"recoMuon.Pt()",Signal_PF_Tight_Cut);
			if(Iso==1 && ID==1  )recottree->Project(Form("histo_Sig1%d_%d",Iso,ID),"recoMuon.Pt()",Signal_PF_Loose_Cut);

			histo_Back1[Iso][ID] = new TH1F(Form("histo_Back1%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Back1[Iso][ID]->Sumw2();

			if(Iso==0 && ID==0  )recottree->Project(Form("histo_Back1%d_%d",Iso,ID),"recoMuon.Pt()",Trk_Tight_Cut);
			if(Iso==0 && ID==1  )recottree->Project(Form("histo_Back1%d_%d",Iso,ID),"recoMuon.Pt()",Trk_Loose_Cut);
			if(Iso==1 && ID==0  )recottree->Project(Form("histo_Back1%d_%d",Iso,ID),"recoMuon.Pt()",PF_Tight_Cut);
			if(Iso==1 && ID==1  )recottree->Project(Form("histo_Back1%d_%d",Iso,ID),"recoMuon.Pt()",PF_Loose_Cut);

			//----------------------------------------------------------------------------------------------

			histo_Sig2[Iso][ID] = new TH1F(Form("histo_Sig2%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Sig2[Iso][ID]->Sumw2();

			if(Iso==0 && ID==0  )recottree_140->Project(Form("histo_Sig2%d_%d",Iso,ID),"recoMuon.Pt()",Signal_Trk_Tight_Cut);
			if(Iso==0 && ID==1  )recottree_140->Project(Form("histo_Sig2%d_%d",Iso,ID),"recoMuon.Pt()",Signal_Trk_Loose_Cut);
			if(Iso==1 && ID==0  )recottree_140->Project(Form("histo_Sig2%d_%d",Iso,ID),"recoMuon.Pt()",Signal_PF_Tight_Cut140);
			if(Iso==1 && ID==1  )recottree_140->Project(Form("histo_Sig2%d_%d",Iso,ID),"recoMuon.Pt()",Signal_PF_Loose_Cut140);

			histo_Back2[Iso][ID] = new TH1F(Form("histo_Back2%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Back2[Iso][ID]->Sumw2();

			if(Iso==0 && ID==0  )recottree_140->Project(Form("histo_Back2%d_%d",Iso,ID),"recoMuon.Pt()",Trk_Tight_Cut);
			if(Iso==0 && ID==1  )recottree_140->Project(Form("histo_Back2%d_%d",Iso,ID),"recoMuon.Pt()",Trk_Loose_Cut);
			if(Iso==1 && ID==0  )recottree_140->Project(Form("histo_Back2%d_%d",Iso,ID),"recoMuon.Pt()",PF_Tight_Cut140);
			if(Iso==1 && ID==1  )recottree_140->Project(Form("histo_Back2%d_%d",Iso,ID),"recoMuon.Pt()",PF_Loose_Cut140);

			//-----------------------------------------------------------------------------------------

			histo_Sig3[Iso][ID] = new TH1F(Form("histo_Sig3%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Sig3[Iso][ID]->Sumw2();

			if(Iso==0 && ID==0  )recottree_200->Project(Form("histo_Sig3%d_%d",Iso,ID),"recoMuon.Pt()",Signal_Trk_Tight_Cut);
			if(Iso==0 && ID==1  )recottree_200->Project(Form("histo_Sig3%d_%d",Iso,ID),"recoMuon.Pt()",Signal_Trk_Loose_Cut);
			if(Iso==1 && ID==0  )recottree_200->Project(Form("histo_Sig3%d_%d",Iso,ID),"recoMuon.Pt()",Signal_PF_Tight_Cut200);
			if(Iso==1 && ID==1  )recottree_200->Project(Form("histo_Sig3%d_%d",Iso,ID),"recoMuon.Pt()",Signal_PF_Loose_Cut200);

			histo_Back3[Iso][ID] = new TH1F(Form("histo_Back3%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Back3[Iso][ID]->Sumw2();

			if(Iso==0 && ID==0  )recottree_200->Project(Form("histo_Back3%d_%d",Iso,ID),"recoMuon.Pt()",Trk_Tight_Cut);
			if(Iso==0 && ID==1  )recottree_200->Project(Form("histo_Back3%d_%d",Iso,ID),"recoMuon.Pt()",Trk_Loose_Cut);
			if(Iso==1 && ID==0  )recottree_200->Project(Form("histo_Back3%d_%d",Iso,ID),"recoMuon.Pt()",PF_Tight_Cut200);
			if(Iso==1 && ID==1  )recottree_200->Project(Form("histo_Back3%d_%d",Iso,ID),"recoMuon.Pt()",PF_Loose_Cut200);

			//-----------------------------------------------------
			histo_Sig4[Iso][ID] = new TH1F(Form("histo_Sig4%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Sig4[Iso][ID]->Sumw2();

			if(Iso==0 && ID==0  )recottree_QCD->Project(Form("histo_Sig4%d_%d",Iso,ID),"recoMuon.Pt()",Signal_Trk_Tight_Cut);
			if(Iso==0 && ID==1  )recottree_QCD->Project(Form("histo_Sig4%d_%d",Iso,ID),"recoMuon.Pt()",Signal_Trk_Loose_Cut);
			if(Iso==1 && ID==0  )recottree_QCD->Project(Form("histo_Sig4%d_%d",Iso,ID),"recoMuon.Pt()",Signal_PF_Tight_Cut);
			if(Iso==1 && ID==1  )recottree_QCD->Project(Form("histo_Sig4%d_%d",Iso,ID),"recoMuon.Pt()",Signal_PF_Loose_Cut);

			histo_Back4[Iso][ID] = new TH1F(Form("histo_Back4%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Back4[Iso][ID]->Sumw2();

			if(Iso==0 && ID==0  )recottree_QCD->Project(Form("histo_Back4%d_%d",Iso,ID),"recoMuon.Pt()",Trk_Tight_Cut);
			if(Iso==0 && ID==1  )recottree_QCD->Project(Form("histo_Back4%d_%d",Iso,ID),"recoMuon.Pt()",Trk_Loose_Cut);
			if(Iso==1 && ID==0  )recottree_QCD->Project(Form("histo_Back4%d_%d",Iso,ID),"recoMuon.Pt()",PF_Tight_Cut);
			if(Iso==1 && ID==1  )recottree_QCD->Project(Form("histo_Back4%d_%d",Iso,ID),"recoMuon.Pt()",PF_Loose_Cut);

			//------------------------------------------------------------------------------------------------

			histo_Sig5[Iso][ID] = new TH1F(Form("histo_Sig5%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
                        histo_Sig5[Iso][ID]->Sumw2();

                        if(Iso==0 && ID==0  )recottree_QCD140->Project(Form("histo_Sig5%d_%d",Iso,ID),"recoMuon.Pt()",Signal_Trk_Tight_Cut);
                        if(Iso==0 && ID==1  )recottree_QCD140->Project(Form("histo_Sig5%d_%d",Iso,ID),"recoMuon.Pt()",Signal_Trk_Loose_Cut);
                        if(Iso==1 && ID==0  )recottree_QCD140->Project(Form("histo_Sig5%d_%d",Iso,ID),"recoMuon.Pt()",Signal_PF_Tight_Cut140);
                        if(Iso==1 && ID==1  )recottree_QCD140->Project(Form("histo_Sig5%d_%d",Iso,ID),"recoMuon.Pt()",Signal_PF_Loose_Cut140);

                        histo_Back5[Iso][ID] = new TH1F(Form("histo_Back5%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
                        histo_Back5[Iso][ID]->Sumw2();

                        if(Iso==0 && ID==0  )recottree_QCD140->Project(Form("histo_Back5%d_%d",Iso,ID),"recoMuon.Pt()",Trk_Tight_Cut);
                        if(Iso==0 && ID==1  )recottree_QCD140->Project(Form("histo_Back5%d_%d",Iso,ID),"recoMuon.Pt()",Trk_Loose_Cut);
                        if(Iso==1 && ID==0  )recottree_QCD140->Project(Form("histo_Back5%d_%d",Iso,ID),"recoMuon.Pt()",PF_Tight_Cut140);
                        if(Iso==1 && ID==1  )recottree_QCD140->Project(Form("histo_Back5%d_%d",Iso,ID),"recoMuon.Pt()",PF_Loose_Cut140);

			//------------------------------------------------------------------------------------------------
			histo_Sig6[Iso][ID] = new TH1F(Form("histo_Sig6%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Sig6[Iso][ID]->Sumw2();

			if(Iso==0 && ID==0  )recottree_QCD200->Project(Form("histo_Sig6%d_%d",Iso,ID),"recoMuon.Pt()",Signal_Trk_Tight_Cut);
			if(Iso==0 && ID==1  )recottree_QCD200->Project(Form("histo_Sig6%d_%d",Iso,ID),"recoMuon.Pt()",Signal_Trk_Loose_Cut);
			if(Iso==1 && ID==0  )recottree_QCD200->Project(Form("histo_Sig6%d_%d",Iso,ID),"recoMuon.Pt()",Signal_PF_Tight_Cut200);
			if(Iso==1 && ID==1  )recottree_QCD200->Project(Form("histo_Sig6%d_%d",Iso,ID),"recoMuon.Pt()",Signal_PF_Loose_Cut200);

			histo_Back6[Iso][ID] = new TH1F(Form("histo_Back6%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Back6[Iso][ID]->Sumw2();

			if(Iso==0 && ID==0  )recottree_QCD200->Project(Form("histo_Back6%d_%d",Iso,ID),"recoMuon.Pt()",Trk_Tight_Cut);
			if(Iso==0 && ID==1  )recottree_QCD200->Project(Form("histo_Back6%d_%d",Iso,ID),"recoMuon.Pt()",Trk_Loose_Cut);
			if(Iso==1 && ID==0  )recottree_QCD200->Project(Form("histo_Back6%d_%d",Iso,ID),"recoMuon.Pt()",PF_Tight_Cut200);
			if(Iso==1 && ID==1  )recottree_QCD200->Project(Form("histo_Back6%d_%d",Iso,ID),"recoMuon.Pt()",PF_Loose_Cut200);

			histo_Eff1[Iso][ID] = new TH1F(Form("histo_Eff1%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Eff2[Iso][ID] = new TH1F(Form("histo_Eff2%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Eff3[Iso][ID] = new TH1F(Form("histo_Eff3%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Eff4[Iso][ID] = new TH1F(Form("histo_Eff4%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Eff5[Iso][ID] = new TH1F(Form("histo_Eff5%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			histo_Eff6[Iso][ID] = new TH1F(Form("histo_Eff6%d_%d",Iso,ID),Form(""),nbin_eff,xmin_eff,xmax_eff);
			//---------------------------histogram design------------------------------------

			histo_Eff1[Iso][ID]->GetYaxis()->SetTitle("Efficiency #mu events");
			histo_Eff1[Iso][ID]->GetXaxis()->SetTitle("#mu P_{t}");
			histo_Eff1[Iso][ID]->SetLineColor(kGreen-1);
			histo_Eff1[Iso][ID]->SetMarkerColor(kGreen-1);
			histo_Eff1[Iso][ID]->SetMarkerStyle(20);
			histo_Eff1[Iso][ID]->SetMarkerSize(size);
			histo_Eff1[Iso][ID]->SetLineWidth(2);

			histo_Eff2[Iso][ID]->SetMarkerStyle(20);
                        histo_Eff2[Iso][ID]->SetMarkerSize(size);
                        histo_Eff2[Iso][ID]->SetLineWidth(2);
                        histo_Eff2[Iso][ID]->SetLineColor(kOrange);
                        histo_Eff2[Iso][ID]->SetMarkerColor(kOrange);	

			histo_Eff3[Iso][ID]->SetMarkerStyle(20);
			histo_Eff3[Iso][ID]->SetMarkerSize(size);
			histo_Eff3[Iso][ID]->SetLineWidth(2);
			histo_Eff3[Iso][ID]->SetLineColor(kRed);
			histo_Eff3[Iso][ID]->SetMarkerColor(kRed);

			histo_Eff4[Iso][ID]->SetLineColor(kBlack);
			histo_Eff4[Iso][ID]->SetMarkerColor(kBlack);
			histo_Eff4[Iso][ID]->SetMarkerSize(size);
			histo_Eff4[Iso][ID]->SetLineWidth(2);
			histo_Eff4[Iso][ID]->SetMarkerStyle(34);

			histo_Eff5[Iso][ID]->SetLineColor(kBlue+3);
                        histo_Eff5[Iso][ID]->SetMarkerColor(kBlue+3);
                        histo_Eff5[Iso][ID]->SetMarkerSize(size);
                        histo_Eff5[Iso][ID]->SetLineWidth(2);
                        histo_Eff5[Iso][ID]->SetMarkerStyle(34);

			histo_Eff6[Iso][ID]->SetLineColor(kBlue);
			histo_Eff6[Iso][ID]->SetMarkerColor(kBlue);
			histo_Eff6[Iso][ID]->SetMarkerSize(size);
			histo_Eff6[Iso][ID]->SetLineWidth(2);
			histo_Eff6[Iso][ID]->SetMarkerStyle(34);

			//-------------------------------------------------------------------
			l_[Iso][ID]->AddEntry(histo_Eff1[Iso][ID],"Phase II Signal PU0", "p");
			l_[Iso][ID]->AddEntry(histo_Eff2[Iso][ID],"Phase II Signal PU140", "p");
			l_[Iso][ID]->AddEntry(histo_Eff3[Iso][ID],"Phase II Signal PU200", "p");
			l_[Iso][ID]->AddEntry(histo_Eff4[Iso][ID],"Phase II QCD0", "p");
			l_[Iso][ID]->AddEntry(histo_Eff5[Iso][ID],"Phase II QCD140", "p");
			l_[Iso][ID]->AddEntry(histo_Eff6[Iso][ID],"Phase II QCD200", "p");

			histo_Eff1[Iso][ID]->Divide(histo_Sig1[Iso][ID],histo_Back1[Iso][ID],1,1,"b");
			histo_Eff2[Iso][ID]->Divide(histo_Sig2[Iso][ID],histo_Back2[Iso][ID],1,1,"b");
			histo_Eff3[Iso][ID]->Divide(histo_Sig3[Iso][ID],histo_Back3[Iso][ID],1,1,"b");
			histo_Eff4[Iso][ID]->Divide(histo_Sig4[Iso][ID],histo_Back4[Iso][ID],1,1,"b");
			histo_Eff5[Iso][ID]->Divide(histo_Sig5[Iso][ID],histo_Back5[Iso][ID],1,1,"b");
			histo_Eff6[Iso][ID]->Divide(histo_Sig6[Iso][ID],histo_Back6[Iso][ID],1,1,"b");

			histo_Eff1[Iso][ID]->SetMaximum(ymax_eff);
			//histo_Eff1[Iso][ID]->SetMinimum(ymin_eff);

			histo_Eff1[Iso][ID]->Draw();
			histo_Eff2[Iso][ID]->Draw("same");
			histo_Eff3[Iso][ID]->Draw("same");
			histo_Eff4[Iso][ID]->Draw("same");
			histo_Eff5[Iso][ID]->Draw("same");
			histo_Eff6[Iso][ID]->Draw("same");

			if(Iso==0 && ID==0  )lt1.DrawLatex(xx_1,yy_1,LatexCutSymbol_Tight+Form("Trk03"));
			if(Iso==0 && ID==1  )lt1.DrawLatex(xx_1,yy_1,LatexCutSymbol_Loose+Form("Trk03"));
			if(Iso==1 && ID==0  )lt1.DrawLatex(xx_1,yy_1,LatexCutSymbol_Tight+Form("PF04"));
			if(Iso==1 && ID==1  )lt1.DrawLatex(xx_1,yy_1,LatexCutSymbol_Loose+Form("PF04"));

			lt2.DrawLatex(x_1,y_1,"CMS");
			lt3.DrawLatex(x_2,y_2,"Simulation");
			lt4.DrawLatex(tx,ty,"14 TeV");
			l_[Iso][ID]->Draw();

			if(Iso==0 && ID==0  )canvIso_[Iso][ID]->Print(Signal_Trk_Tight_Cut+Form(" && Trk03 && Pt>%dGeV && eta>%1.1f, Eff",hEff_pt[ID],hEff_eta[ID])+".png");
			if(Iso==0 && ID==1  )canvIso_[Iso][ID]->Print(Signal_Trk_Loose_Cut+Form(" && Trk03 && Pt>%dGev && eta>%1.1f, Eff",hEff_pt[ID],hEff_eta[ID])+".png");
			if(Iso==1 && ID==0  )canvIso_[Iso][ID]->Print(Trk_Tight_Cut+Form(" && PF04 && Pt>%dGev && eta>%1.1f, Eff",hEff_pt[ID],hEff_eta[ID])+".png");
			if(Iso==1 && ID==1  )canvIso_[Iso][ID]->Print(Trk_Loose_Cut+Form(" && PF04 && Pt>%dGev && eta>%1.1f, Eff",hEff_pt[ID],hEff_eta[ID])+".png");
		}
	}
	cout<<"14 TeV"<<endl;
}
