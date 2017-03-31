from ROOT import gROOT, TCanvas, TF1, gStyle, TStyle, TH1F
import ROOT

gROOT.SetStyle("Plain")
gStyle.SetOptStat(0);
gStyle.SetOptDate(1);

PATH_samples = '/cms/scratch/yonghoJeong57/CMSSW_9_0_0_pre4/src/MuonPerformance/MuonAnalyser/test/'
#ZMM_samples = ['zmm.root','zmm140.root','zmm200.root']
Cut_base = 'fabs(recoMuon.Pt())>15 && fabs(recoMuon.Eta())<2.4'

tfile = ROOT.TFile(PATH_samples+'zmm.root')
recottree = tfile.Get('MuonAnalyser/reco')
tfile2 = ROOT.TFile(PATH_samples+'zmm140.root')
recottree_PU140 = tfile2.Get('MuonAnalyser/reco')
tfile3 = ROOT.TFile(PATH_samples+'zmm200.root')
recottree_PU200 = tfile3.Get('MuonAnalyser/reco')

LineWidth = 2
binning = 100
xmin = 0
xmax = 0.5
#gROOT.Reset()

c1 = TCanvas()
hist1 = TH1F( 'hist1','',binning,xmin,xmax)
hist2 = TH1F( 'hist2','',binning,xmin,xmax)
hist3 = TH1F( 'hist3','',binning,xmin,xmax)
recottree.Project('hist1','recoMuon_TrkIsolation03',Cut_base)
recottree_PU140.Project('hist2','recoMuon_TrkIsolation03',Cut_base)
recottree_PU200.Project('hist3','recoMuon_TrkIsolation03',Cut_base)

#
# Create a one dimensional function and draw it
#
c1.SetLogy()
hist1.SetLineColor(4)
hist2.SetLineColor(2)
hist3.SetLineColor(7)
hist1.SetLineWidth(LineWidth)
hist2.SetLineWidth(LineWidth)
hist3.SetLineWidth(LineWidth)
hist1.Draw()
hist2.Draw('same')
hist3.Draw('same')
#c1.Update()
