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
		gStyle->SetStatFont(42);//word #font
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
	float ly1 = 0.60;
	float lx2 = 0.84;
	float ly2 = 0.75;
	const int VertexCut = 6;
	const int IDCut = 2;//0 = Tight, 1 = Loose
	const int ISOCut = 2;//0 = TrkIso, 1 = PFIso
	double nev_1, nev_2, nev_3, nev_4; 

	TH1F *histo_Iso1[ISOCut][IDCut][VertexCut];
	TH1F *histo_Iso2[ISOCut][IDCut][VertexCut];
	TH1F *histo_Iso3[ISOCut][IDCut][VertexCut];
	TH1F *histo_Iso4[ISOCut][IDCut][VertexCut];
	TCanvas *canvIso_[ISOCut][IDCut][VertexCut];
	TLegend *l_[ISOCut][IDCut][VertexCut];

	int pt = 15;
	float eta = 2.4;
	int hIso_pt[]={pt,pt,pt,pt,pt,pt};//pt
	float hIso_eta[]={eta,eta,eta,eta,eta,eta};//eta
	float hIso_Vertex[]={0.1,0.2,0.3,0.4,0.5};//vertex cut Tight

	TString PATH_samples_ZMM14TeV;
	PATH_samples_ZMM14TeV = "/cms/scratch/quark2930/Work/muon_upgrade/samples/";//KISTI
	//PATH_samples_ZMM14TeV = "/d3/scratch/yonghojeong57/CMSSW_9_0_0_pre4/src/MuonPerformance/MuonAnalyser/test/";//KNU
	//PATH_samples_ZMM14TeV = "/pnfs/user/yonghojeong57/CMSSW_9_0_0_pre4/src/MuonPerformance/MuonAnalyser/test/";//UOS
	//PATH_samples_ZMM14TeV = "/afs/cern.ch/work/y/yjeong/CMSSW_9_0_0_pre4/src/MuonPerformance/MuonAnalyser/test/";//CERN

	TString Cut_base;
	TString Signal_Tight_Cut, Signal_Loose_Cut;
	TString Tight_Cut, Loose_Cut;

	Cut_base = "fabs(recoMuon.Pt())>15 && fabs(recoMuon.Eta())<2.4";
	Tight_Cut = Cut_base+Form(" && recoMuon_isTight==1");
	Loose_Cut = Cut_base+Form(" && recoMuon_isLoose==1");
	Signal_Tight_Cut = Loose_Cut+Form(" && recoMuon_signal==1");
	Signal_Loose_Cut = Tight_Cut+Form(" && recoMuon_signal==1");

	TFile h1(PATH_samples_ZMM14TeV+"zmm.root");
	TFile h2(PATH_samples_ZMM14TeV+"zmm200.root");
	TFile h3(PATH_samples_ZMM14TeV+"qcd.root");
	TFile h4(PATH_samples_ZMM14TeV+"qcd200.root");
	TTree *recottree = (TTree*)h1.Get("MuonAnalyser/reco");
	TTree *recottree_200 = (TTree*)h2.Get("MuonAnalyser/reco");
	TTree *recottree_QCD = (TTree*)h3.Get("MuonAnalyser/reco");
	TTree *recottree_QCD200 = (TTree*)h4.Get("MuonAnalyser/reco");

	for(int Iso=0; Iso<ISOCut; Iso++){
		for(int ID=0; ID<IDCut; ID++){
			for(int Vertex=0; Vertex<VertexCut; Vertex++)
			{
				float nbin_iso = 100;
				float xmin_iso = 0;
				float xmax_iso = 0.5;
				float ymax_iso = 1;
				float ymin_iso = 0.00005;
				float size = 0.8;

				canvIso_[Iso][ID][Vertex] = new TCanvas();
				canvIso_[Iso][ID][Vertex]->SetLogy();
				canvIso_[Iso][ID][Vertex]->SetFillColor(0);
				canvIso_[Iso][ID][Vertex]->SetBorderMode(2);
				canvIso_[Iso][ID][Vertex]->SetFrameFillStyle(3);
				canvIso_[Iso][ID][Vertex]->SetFrameBorderMode(0);
				canvIso_[Iso][ID][Vertex]->SetTickx(1);
				canvIso_[Iso][ID][Vertex]->SetTicky(1);
				canvIso_[Iso][ID][Vertex]->Update();
				canvIso_[Iso][ID][Vertex]->RedrawAxis();
				canvIso_[Iso][ID][Vertex]->GetFrame()->Draw();

				l_[Iso][ID][Vertex] = new TLegend(lx1,ly1,lx2,ly2);
				l_[Iso][ID][Vertex]->SetFillColor(0);
				l_[Iso][ID][Vertex]->SetLineColor(0);
				l_[Iso][ID][Vertex]->SetLineStyle(kSolid);
				l_[Iso][ID][Vertex]->SetLineWidth(1);
				l_[Iso][ID][Vertex]->SetFillStyle(1);
				l_[Iso][ID][Vertex]->SetTextFont(2);
				l_[Iso][ID][Vertex]->SetTextSize(0.035);

				histo_Iso1[Iso][ID][Vertex] = new TH1F(Form("histo_%d_%d_%d",Iso,ID,Vertex),Form(""),nbin_iso,xmin_iso,xmax_iso);
				if(Iso==0 && ID==0 && Vertex!=5)recottree->Project(Form("histo_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Signal_Tight_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));
				if(Iso==0 && ID==1 && Vertex!=5)recottree->Project(Form("histo_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Signal_Loose_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));
				if(Iso==1 && ID==0 && Vertex!=5)recottree->Project(Form("histo_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Signal_Tight_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));
				if(Iso==1 && ID==1 && Vertex!=5)recottree->Project(Form("histo_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Signal_Loose_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));

				if(Iso==0 && ID==0 && Vertex==5)recottree->Project(Form("histo_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Signal_Tight_Cut);
				if(Iso==0 && ID==1 && Vertex==5)recottree->Project(Form("histo_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Signal_Loose_Cut);
				if(Iso==1 && ID==0 && Vertex==5)recottree->Project(Form("histo_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Signal_Tight_Cut);
				if(Iso==1 && ID==1 && Vertex==5)recottree->Project(Form("histo_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Signal_Loose_Cut);

				l_[Iso][ID][Vertex]->AddEntry(histo_Iso1[Iso][ID][Vertex],"Phase II Signal PU0", "p");
				histo_Iso1[Iso][ID][Vertex]->SetLineColor(kGreen-1);
				histo_Iso1[Iso][ID][Vertex]->SetMarkerColor(kGreen-1);
				histo_Iso1[Iso][ID][Vertex]->SetMarkerStyle(20);
				histo_Iso1[Iso][ID][Vertex]->SetMarkerSize(size);
				histo_Iso1[Iso][ID][Vertex]->SetLineWidth(2);
				histo_Iso1[Iso][ID][Vertex]->SetMaximum(ymax_iso);
				histo_Iso1[Iso][ID][Vertex]->SetMinimum(ymin_iso);
				histo_Iso1[Iso][ID][Vertex]->GetYaxis()->SetTitle("Normalized #mu events");
				if(Iso==0)histo_Iso1[Iso][ID][Vertex]->GetXaxis()->SetTitle("#mu TrkIsolation R = 0.3");
				if(Iso==1)histo_Iso1[Iso][ID][Vertex]->GetXaxis()->SetTitle("#mu PFIsolation R = 0.4");

				histo_Iso2[Iso][ID][Vertex] = new TH1F(Form("histo2_%d_%d_%d",Iso,ID,Vertex),Form(""),nbin_iso,xmin_iso,xmax_iso);
				if(Iso==0 && ID==0 && Vertex!=5)recottree_200->Project(Form("histo2_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Signal_Tight_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));
				if(Iso==0 && ID==1 && Vertex!=5)recottree_200->Project(Form("histo2_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Signal_Loose_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));
				if(Iso==1 && ID==0 && Vertex!=5)recottree_200->Project(Form("histo2_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Signal_Tight_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));
				if(Iso==1 && ID==1 && Vertex!=5)recottree_200->Project(Form("histo2_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Signal_Loose_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));

				if(Iso==0 && ID==0 && Vertex==5)recottree_200->Project(Form("histo2_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Signal_Tight_Cut);
                                if(Iso==0 && ID==1 && Vertex==5)recottree_200->Project(Form("histo2_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Signal_Loose_Cut);
                                if(Iso==1 && ID==0 && Vertex==5)recottree_200->Project(Form("histo2_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Signal_Tight_Cut);
                                if(Iso==1 && ID==1 && Vertex==5)recottree_200->Project(Form("histo2_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Signal_Loose_Cut);

				histo_Iso2[Iso][ID][Vertex]->SetMarkerStyle(20);
				histo_Iso2[Iso][ID][Vertex]->SetMarkerSize(size);
				histo_Iso2[Iso][ID][Vertex]->SetLineWidth(2);
				l_[Iso][ID][Vertex]->AddEntry(histo_Iso2[Iso][ID][Vertex],"Phase II Signal PU200", "p");
				histo_Iso2[Iso][ID][Vertex]->SetLineColor(kRed);
				histo_Iso2[Iso][ID][Vertex]->SetMarkerColor(kRed);

				histo_Iso3[Iso][ID][Vertex] = new TH1F(Form("histo3_%d_%d_%d",Iso,ID,Vertex),Form(""),nbin_iso,xmin_iso,xmax_iso);
				if(Iso==0 && ID==0 && Vertex!=5)recottree_QCD->Project(Form("histo3_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Tight_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));
				if(Iso==0 && ID==1 && Vertex!=5)recottree_QCD->Project(Form("histo3_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Loose_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));
				if(Iso==1 && ID==0 && Vertex!=5)recottree_QCD->Project(Form("histo3_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Tight_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));
				if(Iso==1 && ID==1 && Vertex!=5)recottree_QCD->Project(Form("histo3_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Loose_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));

				if(Iso==0 && ID==0 && Vertex==5)recottree_QCD->Project(Form("histo3_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Tight_Cut);
                                if(Iso==0 && ID==1 && Vertex==5)recottree_QCD->Project(Form("histo3_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Loose_Cut);
                                if(Iso==1 && ID==0 && Vertex==5)recottree_QCD->Project(Form("histo3_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Tight_Cut);
                                if(Iso==1 && ID==1 && Vertex==5)recottree_QCD->Project(Form("histo3_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Loose_Cut);

				histo_Iso3[Iso][ID][Vertex]->SetLineColor(kBlack);
				histo_Iso3[Iso][ID][Vertex]->SetMarkerColor(kBlack);
				histo_Iso3[Iso][ID][Vertex]->SetMarkerSize(size);
				histo_Iso3[Iso][ID][Vertex]->SetLineWidth(2);
				histo_Iso3[Iso][ID][Vertex]->SetMarkerStyle(34);
				l_[Iso][ID][Vertex]->AddEntry(histo_Iso3[Iso][ID][Vertex],"Phase II QCD0", "p");

				histo_Iso4[Iso][ID][Vertex] = new TH1F(Form("histo4_%d_%d_%d",Iso,ID,Vertex),Form(""),nbin_iso,xmin_iso,xmax_iso);
				if(Iso==0 && ID==0 && Vertex!=5)recottree_QCD200->Project(Form("histo4_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Tight_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));
				if(Iso==0 && ID==1 && Vertex!=5)recottree_QCD200->Project(Form("histo4_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Loose_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));
				if(Iso==1 && ID==0 && Vertex!=5)recottree_QCD200->Project(Form("histo4_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Tight_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));
				if(Iso==1 && ID==1 && Vertex!=5)recottree_QCD200->Project(Form("histo4_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Loose_Cut+Form("&& abs(recoMuon_poszPV0 - recoMuon_poszSimPV) < %f",hIso_Vertex[Vertex]));

				if(Iso==0 && ID==0 && Vertex==5)recottree_QCD200->Project(Form("histo4_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Tight_Cut);
                                if(Iso==0 && ID==1 && Vertex==5)recottree_QCD200->Project(Form("histo4_%d_%d_%d",Iso,ID,Vertex),"recoMuon_TrkIsolation03",Loose_Cut);
                                if(Iso==1 && ID==0 && Vertex==5)recottree_QCD200->Project(Form("histo4_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Tight_Cut);
                                if(Iso==1 && ID==1 && Vertex==5)recottree_QCD200->Project(Form("histo4_%d_%d_%d",Iso,ID,Vertex),"recoMuon_PFIsolation04",Loose_Cut);

				histo_Iso4[Iso][ID][Vertex]->SetLineColor(kBlue);
				histo_Iso4[Iso][ID][Vertex]->SetMarkerColor(kBlue);
				histo_Iso4[Iso][ID][Vertex]->SetMarkerSize(size);
				histo_Iso4[Iso][ID][Vertex]->SetLineWidth(2);
				histo_Iso4[Iso][ID][Vertex]->SetMarkerStyle(34);
				l_[Iso][ID][Vertex]->AddEntry(histo_Iso4[Iso][ID][Vertex],"Phase II QCD200", "p");

				nev_1 = histo_Iso1[Iso][ID][Vertex]->GetEntries();
				histo_Iso1[Iso][ID][Vertex]->Scale(1/nev_1);
				nev_2 = histo_Iso2[Iso][ID][Vertex]->GetEntries();
				histo_Iso2[Iso][ID][Vertex]->Scale(1/nev_2);
				nev_3 = histo_Iso3[Iso][ID][Vertex]->GetEntries();
				histo_Iso3[Iso][ID][Vertex]->Scale(1/nev_3);
				nev_4 = histo_Iso4[Iso][ID][Vertex]->GetEntries();
				histo_Iso4[Iso][ID][Vertex]->Scale(1/nev_4);

				histo_Iso1[Iso][ID][Vertex]->Draw();
				histo_Iso2[Iso][ID][Vertex]->Draw("same");
				histo_Iso3[Iso][ID][Vertex]->Draw("same");
				histo_Iso4[Iso][ID][Vertex]->Draw("same");

				if(ID==0 && Vertex!=5)lt1.DrawLatex(xx_1,yy_1,Form("#splitline{Z/#gamma* #rightarrow #font[12]{#mu#mu} , P_{t} > %d GeV, Tight #mu, |#eta| < %1.1f,}{|Z_{PV0} - Z_{Gen vtx #mu}| < %1.1f}",hIso_pt[Vertex],hIso_eta[Vertex],hIso_Vertex[Vertex]));
				if(ID==1 && Vertex!=5)lt1.DrawLatex(xx_1,yy_1,Form("#splitline{Z/#gamma* #rightarrow #font[12]{#mu#mu} , P_{t} > %d GeV, Loose #mu, |#eta| < %1.1f,}{|Z_{PV0} - Z_{Gen vtx #mu}| < %1.1f}",hIso_pt[Vertex],hIso_eta[Vertex],hIso_Vertex[Vertex]));

				if(ID==0 && Vertex==5)lt1.DrawLatex(xx_1,yy_1,Form("Z/#gamma* #rightarrow #font[12]{#mu#mu} , P_{t} > %d GeV, Tight #mu, |#eta| < %1.1f,",hIso_pt[Vertex],hIso_eta[Vertex]));
                                if(ID==1 && Vertex==5)lt1.DrawLatex(xx_1,yy_1,Form("Z/#gamma* #rightarrow #font[12]{#mu#mu} , P_{t} > %d GeV, Loose #mu, |#eta| < %1.1f,",hIso_pt[Vertex],hIso_eta[Vertex]));

				lt2.DrawLatex(x_1,y_1,"CMS");
				lt3.DrawLatex(x_2,y_2,"Simulation");
				lt4.DrawLatex(tx,ty,"14 TeV");
				l_[Iso][ID][Vertex]->Draw();

				//if(ID==0)canvIso_[Iso][ID][Vertex]->Print(Form("PFIsolation04_Tight_cutZ<%1.1f.png",hIso_Vertex[Vertex]));
				if(Iso==0 && ID==0 && Vertex!=5)canvIso_[Iso][ID][Vertex]->Print(Signal_Tight_Cut+Form(" && Trk03_cutZ<%1.1f_Pt>%dGeV_eta>%1.1f",hIso_Vertex[Vertex],hIso_pt[Vertex],hIso_eta[Vertex])+".png");
				if(Iso==0 && ID==1 && Vertex!=5)canvIso_[Iso][ID][Vertex]->Print(Signal_Loose_Cut+Form(" && Trk03_cutZ<%1.1f_Pt>%dGev_eta>%1.1f",hIso_Vertex[Vertex],hIso_pt[Vertex],hIso_eta[Vertex])+".png");
				if(Iso==1 && ID==0 && Vertex!=5)canvIso_[Iso][ID][Vertex]->Print(Tight_Cut+Form(" && PF04_cutZ<%1.1f_Pt>%dGev_eta>%1.1f",hIso_Vertex[Vertex],hIso_pt[Vertex],hIso_eta[Vertex])+".png");
				if(Iso==1 && ID==1 && Vertex!=5)canvIso_[Iso][ID][Vertex]->Print(Loose_Cut+Form(" && PF04_cutZ<%1.1f_Pt>%dGev_eta>%1.1f",hIso_Vertex[Vertex],hIso_pt[Vertex],hIso_eta[Vertex])+".png");

				if(Iso==0 && ID==0 && Vertex==5)canvIso_[Iso][ID][Vertex]->Print(Signal_Tight_Cut+Form(" && Trk03 && Pt>%dGeV && #eta>%1.1f",hIso_pt[Vertex],hIso_eta[Vertex])+".png");
                                if(Iso==0 && ID==1 && Vertex==5)canvIso_[Iso][ID][Vertex]->Print(Signal_Loose_Cut+Form(" && Trk03 && Pt>%dGev && #eta>%1.1f",hIso_pt[Vertex],hIso_eta[Vertex])+".png");
                                if(Iso==1 && ID==0 && Vertex==5)canvIso_[Iso][ID][Vertex]->Print(Tight_Cut+Form(" && PF04 && Pt>%dGev && #eta>%1.1f",hIso_pt[Vertex],hIso_eta[Vertex])+".png");
                                if(Iso==1 && ID==1 && Vertex==5)canvIso_[Iso][ID][Vertex]->Print(Loose_Cut+Form(" && PF04 && Pt>%dGev && eta>%1.1f",hIso_pt[Vertex],hIso_eta[Vertex])+".png");
			}
		}
	}
	cout<<"14 TeV"<<endl;
}
