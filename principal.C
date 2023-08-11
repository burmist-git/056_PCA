#include "TPrincipal.h"
#include <iomanip>
   
Int_t principal() {

  Int_t n=2;
  Int_t m=1000;
  
  TPrincipal* principal = new TPrincipal(n,"N");
  
  TRandom3* rnd = new TRandom3(131231);
  
  Double_t* data = new Double_t[n];


  TMatrixD A(m,2);
  TMatrixD B(m,2);


  
  Double_t x, y;

  TGraph *gr = new TGraph();

  double *data_data = new double[m*n];

  Int_t nm_count = 0;
  
  for (Int_t i = 0; i < m; i++) {
    x = rnd->Uniform(-1,1);
    y = x;
    x += rnd->Gaus(0,0.1);
    y += rnd->Gaus(0,0.1);
    data[0] = x;
    data[1] = y;
    data_data[nm_count] = x;
    nm_count++;
    data_data[nm_count] = y;
    nm_count++;
    gr->SetPoint(gr->GetN(),x,y);
    principal->AddRow(data);
  }
  // Do the actual analysis
  principal->MakePrincipals();

  // Print out the result on
  principal->Print();

  //cout<<principal->GetEigenVectors()->GetNcols()<<endl
  //<<principal->GetEigenVectors()->GetNrows()<<endl;


  //const TMatrixD* eigenV = principal->GetEigenVectors();

  // = new double[4];
  //auto data_v = new double [2][2];
  //double data_v[2][2];
  const double *data_v = principal->GetEigenVectors()->GetMatrixArray();
  const TVectorD* V_v  = principal->GetEigenValues();

  const double *data_v_v = V_v->GetMatrixArray();
  //
  cout<<V_v->GetNrows()<<endl;
  //
  cout<<data_v_v[0]<<endl;
  cout<<data_v[0]<<endl;
  cout<<data_v[1]<<endl;
  cout<<data_v_v[1]<<endl;
  cout<<data_v[2]<<endl;
  cout<<data_v[3]<<endl;

  const double *cov_v = principal->GetCovarianceMatrix()->GetMatrixArray();

  cout<<principal->GetCovarianceMatrix()->GetNcols()<<endl
      <<principal->GetCovarianceMatrix()->GetNrows()<<endl;

  A.Use(m,n,data_data);
  B.Use(m,n,data_data);
  
  cout<<A.GetNcols()<<endl
      <<A.GetNrows()<<endl;

  cout<<B.GetNcols()<<endl
      <<B.GetNrows()<<endl;
    
  //TMatrixD C = A*(B.Transpose());
  TMatrixD C(n,m);
  C.Transpose(B);
  //B.Transpose();

  TMatrixD D(m,m);

  D = A*C;

  TPrincipal* principal_n = new TPrincipal(m,"N");
  
  cout<<C.GetNcols()<<endl
      <<C.GetNrows()<<endl;

  cout<<D.GetNcols()<<endl
      <<D.GetNrows()<<endl;

  
  //const Double_t pData[2][2] = ;
  //(0,0);
  //
  //  
  //GetNcols
  //

  //principal->
  

  // Test the PCA 
  principal->Test();

  // Make some histograms of the orginal, principal, residue, etc data 
  //principal->MakeHistograms();
  
  // Make two functions to map between feature and pattern space 
  //principal->MakeCode();

  // Start a browser, so that we may browse the histograms generated
  // above 
  //TBrowser* b = new TBrowser("principalBrowser", principal);

  gr->Draw("AP");
  
  return 0;
  
}
