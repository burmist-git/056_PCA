#include "TPrincipal.h"

 	

// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include <vector>

Int_t principalfaces(){

  Int_t n=1024;
  Int_t l=32;
  Int_t m=5000;
  
  TPrincipal* principal = new TPrincipal(n,"N");
    
  Double_t* data = new Double_t[n];  

  Double_t val;
  Int_t evID;

  std::vector<TH2D*> h2_faces_v;

  Int_t jj = 0;
  
  ifstream file_cvs ("ex7faces.cvs");
 if(file_cvs.is_open()){
        for(Int_t i = 0; i < m; i++){
	  file_cvs>>evID;
      TString name = "h2";
      name += "_id";
      name += i;
      TH2D *h2 = new TH2D(name.Data(),name.Data(),l,0,l,l,0,l);
      for(Int_t j = 0; j < n; j++){
	file_cvs >> val;
	data[j] = val;
	if(jj == 32)
	jj = 0;
	h2->SetBinContent(32-j/32+1,32-jj+1,val);
	jj++;	
      }
      h2_faces_v.push_back(h2);
      //break;
      principal->AddRow(data);
    }
    file_cvs.close();
  }
  //
  gStyle->SetPalette(kGreyScale);
  h2_faces_v.at(0)->Draw("ZCOLOR");
  /*
  //
  // Do the actual analysis
  principal->MakePrincipals();
  
  // Print out the result on
  principal->Print();

  Int_t ii_vec = 1;
  TString name = "h2";
  name += "_EigenVec";
  name += ii_vec ;  
  TH2D *h2 = new TH2D(name.Data(),name.Data(),l,0,l,l,0,l);

  const double *data_v = principal->GetEigenVectors()->GetMatrixArray();

  jj=0;
  for(Int_t j = 0; j < n; j++){
    if(jj == 32)
      jj = 0;
    h2->SetBinContent(32-j/32+1,32-jj+1,data_v[j+ii_vec*n]);
    jj++;	
  }
  
  cout<<principal->GetEigenVectors()->GetNcols()<<endl
      <<principal->GetEigenVectors()->GetNrows()<<endl;
  
  h2->Draw("ZCOLOR");
  */
  //const TMatrixD* eigenV = principal->GetEigenVectors();

  // = new double[4];
  //auto data_v = new double [2][2];
  //double data_v[2][2];
  /*

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
  */
  
  return 0;
  
}
