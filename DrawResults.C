void DrawResults() {

	TFile *fin;
	TH1D *hdNdPt;
	fin = TFile::Open("result.root","read");
	hdNdPt = (TH1D*)fin->Get("hPt");

    double noEvents = 100000;
    double norm =  1./(2*TMath::Pi())/1.6;  ///1.6;
    hdNdPt->Scale(norm/noEvents);
    scaleNotEquidistantHisto(hdNdPt);

	int logy =1;
	double ptMin = 0.1, ptMax = 100;
	double Low = 1e-8,Upp = 1e2;

	mc(1,1.1);
	gStyle->SetOptStat(0);gStyle->SetOptTitle(0);
	gStyle->SetMarkerSize(1.6);
	mpad->SetLogx(0);mpad->SetGridx(0);
	mpad->SetLogy(logy);mpad->SetGridy(0);
	gPad->SetLeftMargin(0.17);

	hfr = new TH2F("hfr"," ", 10, ptMin, ptMax, 10, Low, Upp);
	hset( *hfr, "p_{T}  [GeV/c]"," 1/N_{eve} 1/(2#pip_{T}) dN/dp_{T} [ (GeV/c)^{-2} ]");
	//hset( *hfr, "p_{T}  [GeV/c]"," 1/N_{eve} 1/(2#pip_{T}) dN/dp_{T} [ (GeV/c)^{-2} ]");
	hfr->Draw();

	int idat=0;
	hdNdPt->SetMarkerStyle(24);
	hdNdPt->SetMarkerColor(1);
	hdNdPt->Draw("same");

	leg = new TLegend(0.5,0.7,0.8,0.90,NULL,"brNDC");
	leg->SetFillStyle(0);leg->SetBorderSize(0);leg->SetTextSize(0.04);
	leg->AddEntry(hdNdPt, "#pi^{0} pp #sqrt{s}=14 TeV","p");
	leg->Draw();
}
