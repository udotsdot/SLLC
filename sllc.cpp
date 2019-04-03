#include <iostream>
#include <cstdlib>
#include <conio.h> 
using namespace std;

class sllc
{
public:

  int urut;
  sllc *next; 
}; 
  sllc *depan_ptr = NULL;
  sllc *posisi;         
  int option = 0; 

// Tambah Data Depan
void tambah_data_depan_list()
{
  sllc *baru;
  baru = new sllc;
  cout << "Masukkan Data     : ";
  cin >> baru->urut;
  baru->next = NULL;
  if(depan_ptr == NULL)
  {
    depan_ptr=baru;
    depan_ptr->next = NULL;
  }
  else
  {
    baru->next = depan_ptr;
    depan_ptr = baru;
  }
} 

// Tambah data belakang
void tambah_data_sllc_di_belakang()
  {
  sllc *temp, *temp2;   
  temp = new sllc; 
  cout << "Masukkan Data     : ";
  cin >>   temp->urut;
  temp->next = NULL; 


  if (depan_ptr == NULL)
  {
    depan_ptr = temp;
    posisi = depan_ptr;
  }
  else
  {
    temp2 = depan_ptr;

    while (temp2->next != NULL)
    {
      temp2 = temp2->next; 
      
    }
  temp2->next = temp;
  }
} 
// Menampilkan list
void display_list()
{
  sllc *temp;
  temp = depan_ptr;
  cout << endl;
  cout << "DATA [";  
  if (temp == NULL)
    cout << "Data kosong!]" << endl;
  else
  {
    while (temp != NULL)
    {  
     
     cout << "" << temp->urut << ",";
     
     if (temp == posisi)
        cout << "";

     temp = temp->next; 
    }
    cout << "] ";  
    cout << "" << endl;
  }
  
} 
//Hapus data depan
void hapus_depan_sllc()
{
  sllc *temp;
  temp = depan_ptr;
  depan_ptr = depan_ptr->next;
  delete temp;
} 
//Hapus data belakang
void hapus_belakang_sllc()
{
  sllc *temp1, *temp2;
  if (depan_ptr == NULL)
    cout << "Data kosong!" << endl;
  else
  {
    temp1 = depan_ptr;
    if (temp1->next == NULL)
    {
      delete temp1;
      depan_ptr = NULL;
    }
    else 
    {
      while (temp1->next != NULL)
      {
        temp2 = temp1;
        temp1 = temp1->next;
      }
      delete temp1;
      temp2->next = NULL;
    }

   }
} 
