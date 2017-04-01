int electrifield(){
	double const ww = 1.8; // mm 
	double const ll = 1.4; // anode-cathod pitch mm
	double const wd = 0.05; // wire diameter mm
	int const volt = 2900;
	double const s = TMath::Pi()/ww;
	double const epsilon = 8.854e-3; // pF/mm
	double const C = 2*epsilon*ww/((TMath::Pi()*ll) - TMath::Log(2*TMath::Pi()*wd/ww));
	cout << C << " pF/mm"<<endl;
	double alpha = C*volt/2*epsilon*ww;
	TF1* efield = new TF1("efield","[0]*(TMath::Power((1+TMath::Tan([1]*x)*TMath::Tan([1]*x)*TMath::TanH([1]*0.06)*TMath::TanH([1]*0.06)),.5)*(TMath::Power(TMath::Tan([1]*x)*TMath::Tan([1]*x)*TMath::TanH([1]*0.06)*TMath::TanH([1]*0.06),-.5)))",0.05,.9);
	efield->SetParameters(alpha,s);
	efield->Draw();
	return 0;
}

