#include <iostream>
using namespace std;

class Karyawan {
private:
    int id[99], notelp[99];
    int n;
    string nama[99], jabatan[99];
    
public:
    void input() {
    	cout << "\n-----------------------------\n";
        cout << "    Input Data Karyawan\n";
        cout << "-----------------------------\n";
        cout << "\nMasukkan jumlah data : ";
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            cout << "\nMasukkan Data ke-" << i+1 << endl;
            cout << "Masukkan ID      : ";
            cin >> id[i];
            cout << "Masukkan Nama    : ";
            cin.ignore();
            getline(cin, nama[i]);
            cout << "Masukkan Jabatan : ";
            getline(cin, jabatan[i]);
            cout << "Masukkan No Telp : ";
            cin >> notelp[i];
        }
    }
    
    void tampil() {
        cout << "\n-----------------------------\n";
        cout << "    Data Karyawan\n";
        cout << "-----------------------------\n";
        for (int i = 0; i < n; i++) {
            cout << "ID      : " << id[i] << endl;
            cout << "Nama    : " << nama[i] << endl;
            cout << "Jabatan : " << jabatan[i] << endl;
            cout << "No Telp : " << notelp[i] << endl;
            cout << endl;
        }
        cout << "-----------------------------\n\n";
    }
    
    void ascending() {
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (id[j] > id[j+1]) {
                   
                    int temp_id = id[j];
                    id[j] = id[j+1];
                    id[j+1] = temp_id;
                    
                    string temp_nama = nama[j];
                    nama[j] = nama[j+1];
                    nama[j+1] = temp_nama;
                    
                    string temp_jabatan = jabatan[j];
                    jabatan[j] = jabatan[j+1];
                    jabatan[j+1] = temp_jabatan;
                    
                    int temp_notelp = notelp[j];
                    notelp[j] = notelp[j+1];
                    notelp[j+1] = temp_notelp;
                }
            }
        }
        cout << "\nData telah diurutkan secara Ascending berdasarkan ID\n";
    }
    
    void descending() {
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (id[j] < id[j+1]) {
                    
                    int temp_id = id[j];
                    id[j] = id[j+1];
                    id[j+1] = temp_id;
                    
                    string temp_nama = nama[j];
                    nama[j] = nama[j+1];
                    nama[j+1] = temp_nama;
                   
                    string temp_jabatan = jabatan[j];
                    jabatan[j] = jabatan[j+1];
                    jabatan[j+1] = temp_jabatan;
                    
                    int temp_notelp = notelp[j];
                    notelp[j] = notelp[j+1];
                    notelp[j+1] = temp_notelp;
                }
            }
        }
        cout << "\nData telah diurutkan secara Descending berdasarkan ID\n";
    }
    
    void cari() {
    	tampil();
        if (n == 0) {
            cout << "\nData karyawan masih kosong. Silakan input data terlebih dahulu.\n";
            return;
        }
        
        int key;
        cout << "\nMasukkan ID yang ingin dicari : ";
        cin >> key;
        
        int left = 0, right = n - 1;
        bool found = false;
        int index = -1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (id[mid] == key) {
                found = true;
                index = mid;
                break;
            } else if (id[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        if (found) {
            cout << "\nData ditemukan:\n";
            cout << "-----------------------------\n";
            cout << "ID      : " << id[index] << endl;
            cout << "Nama    : " << nama[index] << endl;
            cout << "Jabatan : " << jabatan[index] << endl;
            cout << "No Telp : " << notelp[index] << endl;
            cout << "-----------------------------\n";
        } else {
            cout << "\nData dengan ID " << key << " tidak ditemukan.\n";
        }
    }
    
    void menu() {
        int pilMenu;
        
        do {
            cout << "\n---------------------------------------\n";
            cout << "  	  PT. Quairo\n";
            cout << "---------------------------------------\n";
            cout << "1. Input Data Karyawan\n";
            cout << "2. Tampilkan Data Karyawan\n";
            cout << "3. Sorting Data secara Ascending\n";
            cout << "4. Sorting Data secara Descending\n";
            cout << "5. Cari Data berdasarkan ID\n";
            cout << "6. Keluar\n";
            cout << "---------------------------------------\n";
            cout << "Pilih Menu : ";
            cin >> pilMenu;
            
            switch(pilMenu) {
                case 1:
                    input();
                    break;
                case 2:
                    tampil();
                    break;
                case 3:
                    ascending();
                    tampil();
                    break;
                case 4:
                    descending();
                    tampil();
                    break;
                case 5:
                    cari();
                    break;
                case 6:
                    cout << "Terima Kasih!\n";
                    break;
                default:
                    cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                    break;
            }
        } while (pilMenu != 6);
    }
};

int main() {
    Karyawan k;
    k.menu();
    return 0;
}

