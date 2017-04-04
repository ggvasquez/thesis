int electrifield(){
	double const ww = 1.8; // mm 
	double const ll = 1.4; // anode-cathod pitch mm
	double const wd = 0.05; // wire diameter mm
	double const volt = 2.900;
	double const s = TMath::Pi()/ww;
	double const epsilon = 8.854e-2; // pF/cm
	double const C = 2*epsilon/((TMath::Pi()*ll/ww) - TMath::Log(2*TMath::Pi()*wd/ww));
	cout << C*0.18 << " pF"<<endl;
	double alpha = C*volt/.2*epsilon*ww;
	TF1* efield = new TF1("efield","[0]*(TMath::Power((1+TMath::Tan([1]*x)*TMath::Tan([1]*x)*TMath::TanH([1]*0.06)*TMath::TanH([1]*0.06)),.5)*(TMath::Power(TMath::Tan([1]*x)*TMath::Tan([1]*x)*TMath::TanH([1]*0.06)*TMath::TanH([1]*0.06),-.5)))",0.05,1.75);
	efield->SetParameters(alpha,s);
	efield->Draw();
	return 0;
}

