{
	gROOT->SetStyle("Plain");//Pub, ATLAS, Plain
	gStyle->SetOptDate(1);//display date position
	gStyle->SetOptStat(0);//To display the mean and RMS: SetOptStat("mr"), nemruoi, ;
	//---------------------------------------------------
	TLatex lt1;
	lt1.SetTextAlign(22);
	lt1.SetNDC();
	lt1.SetTextFont(132);
	lt1.SetTextAngle(0);
	lt1.SetTextSize(0.045);

	TLatex lt2;
	lt2.SetTextAlign(12);
	lt2.SetNDC();
	lt2.SetTextFont(61);
	lt2.SetTextAngle(0);
	lt2.SetTextSize(0.058);

	TLatex lt3;
	lt3.SetTextAlign(12);
	lt3.SetNDC();
	lt3.SetTextAngle(0);
	lt3.SetTextFont(52);
	lt3.SetTextSize(0.045);

	TLatex lt4;
	lt4.SetTextAlign(12);
	lt4.SetNDC();
	lt4.SetTextAngle(0);
	lt4.SetTextFont(42);
	lt4.SetTextSize(0.045);

	TCanvas *c1 = new TCanvas();
	//c1->SetLogy();
	c1->SetFillColor(0);
	c1->SetBorderMode(2);//outLine Color
	c1->SetFrameFillStyle(3);
	c1->SetFrameBorderMode(0);
	c1->SetTickx(1);
	c1->SetTicky(1);
	c1->Update();
	c1->RedrawAxis();
	c1->GetFrame()->Draw();

	float lx1=0.66;
	float ly1=0.40;
	float lx2=0.85;
	float ly2=0.55;

	TLegend *l1;
	l1 = new TLegend(lx1,ly1,lx2,ly2);
	l1->SetFillColor(0);
	l1->SetLineColor(0);
	l1->SetLineStyle(kSolid);
	l1->SetLineWidth(1);
	l1->SetFillStyle(1);
	l1->SetTextSize(0.035);

	//----------------------------------------------------------------------------------
	TString PATH_samples_ZMM14TeV;
	PATH_samples_ZMM14TeV = "/d3/scratch/yonghojeong57/CMSSW_9_0_0_pre4/src/MuonPerformance/MuonAnalyser/test/";

	TString Cut_base;
	Cut_base = "fabs(recoMuon.Pt())>15 && fabs(recoMuon.Eta())<2.4 &&";

	TFile h(PATH_samples_ZMM14TeV+"zmm.root");
	TTree *recottree = (TTree*)h.Get("MuonAnalyser/reco");

	TH1F *hSigEff, *hdSigEff;
	TH1F *hBkgRej, *hdBkgRej;

	TH1F *hSig, *hBkg;

	//------------------------------------------------noPU--------------------------------------------

	const int nbin = 1000;
	float xmin = 0;
	float xmax = 120;

	hSig = new TH1F(Form("hSig"),Form("eff_reco #mu R03"),nbin,xmin,xmax);
	hBkg = new TH1F(Form("hBkg"),Form("eff_reco #mu R03"),nbin,xmin,xmax);
	//-----------------------------
	hSigEff = new TH1F(Form("hSigEff"),Form("reco #mu Pt _{TrkIso03_0.05}"),nbin,xmin,xmax);
	hdSigEff = new TH1F(Form("hdSigEff"),Form("reco #mu Pt _{TrkIso03_0.05}"),nbin,xmin,xmax);
	hBkgRej = new TH1F(Form("hBkgRej"),Form("reco #mu Pt _{TrkIso03_0.05}"),nbin,xmin,xmax);
	hdBkgRej = new TH1F(Form("hdBkgRej"),Form("reco #mu Pt _{TrkIso03_0.05}"),nbin,xmin,xmax);

	//--------------------------------------------------

	recottree->Project(Form("hSigEff"),"recoMuon.Pt()",Cut_base+Form("recoMuon_signal==1"));
	hSigEff->Integral(0,nbin+1);
	recottree->Project(Form("hdSigEff"),"recoMuon.Pt()",Cut_base+Form("recoMuon_signal==1&&recoMuon_TrkIsolation03<0.05"));
	hdSigEff->Integral(0,nbin+1);

	recottree->Project(Form("hBkgRej"),"recoMuon.Pt()",Cut_base+Form("recoMuon_signal==1"));
	hBkgRej->Integral(0,nbin+1);
	recottree->Project(Form("hdBkgRej"),"recoMuon.Pt()",Cut_base+Form("recoMuon_signal==1&&recoMuon_TrkIsolation03<0.05"));
	hdBkgRej->Integral(0,nbin+1);

	hSig->Divide(hdSigEff,hSigEff,1,1,"b");
	hBkg->Divide(hdBkgRej,hBkgRej,1,1,"b");

	double TSigEff[nbin] = {0,};
	double TBkgRej[nbin] = {0,};
	double fMSig[nbin] = {0,};
	double fMBkg[nbin] = {0,};
	double fSigEff[nbin] = {0,};
	double fBkgRej[nbin] = {0,};
	for(int i=0; i<nbin+1; i++){
		fMSig[i] = hSigEff->Integral(0,i+1);
		fMBkg[i] = hBkgRej->Integral(0,i+1);

		fSigEff[i] = hdSigEff->Integral(0,i+1)/fMSig[i];
		fBkgRej[i] = 1.0 - hdBkgRej->Integral(0,i+1)/fMBkg[i];

		TSigEff[i] = fSigEff[i];
		TBkgRej[i] = fBkgRej[i];

		cout<<TSigEff[i]<<" , "<<TBkgRej[i]<<endl;

		//new TCanvas;
		//TGraph *graphROC = new TGraph(i,TSigEff[i],TBkgRej[i]);
		//graphROC->Draw();
	}
	hSig->GetYaxis()->SetTitle("Efficiency");
	hSig->GetXaxis()->SetTitle("P_{t}(Reco #mu)(TrkR03<0.05)");
	hSig->SetTitle("");

	hSig->SetLineColor(kBlue);
	hSig->SetMarkerStyle(20);
	hSig->SetMarkerSize(1.3);
	hSig->SetMarkerColor(kBlue);
	hSig->SetLineWidth(2);

	hBkg->SetMarkerStyle(20);
	hBkg->SetMarkerSize(1.3);
	hBkg->SetMarkerColor(kRed);

	//-------------------------------------------------------TLegend---------------------------------------
	l1->AddEntry(hSig,"Phase II PU0","p");
	//-----------------------------------Coordinate of CMS Simulation------------------------------------------------------------
	float x_1 = 0.1;
	const float y_1 = 0.94;
	float x_2 = x_1+0.095;
	float y_2 = y_1-0.005;
	//------------------------------------Coordinate of formula LatexBox---------------------------------------
	float xx_1 = 0.5;
	float yy_1 = y_1-0.5;
	//--------------------------------------Set Maximum histo---------------------------------
	float ymax_1 = 1.25;
	float ymin_1 = 0;
	//-------------------------------------ExtraText--------------------------------
	float tx = 0.8;
	float ty = 0.93;

	//----------------------------------------------------TCanvas-------------------------------------

	c1->cd();
	hSig->SetMaximum(ymax_1);
	hSig->SetMinimum(ymin_1);
	hSig->Draw();
	hBkg->Draw("same");
	l1->Draw();
	lt1.DrawLatex(xx_1,yy_1,"Z/#gamma* #rightarrow #mu#mu, P_{t}>5 GeV");
	//lt1.DrawLatex(xx_1,yy_1,"10 #mu per events and QCD events, P_{t}>5 GeV");
	lt2.DrawLatex(x_1,y_1,"CMS");
	lt3.DrawLatex(x_2,y_2,"Simulation");
	lt4.DrawLatex(tx,ty,"14 TeV");
	//c1->Print("roccurve.png");
}
