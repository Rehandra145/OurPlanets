#include <bits/stdc++.h>
#include <unistd.h> //untuk menggunakan fungsi sleep
#define MAX 7
using namespace std;

//Deklarasi struct yang digunakan//
struct Planet{
	string data[MAX]; 
};//Struct untuk menyimpan data planet

struct QA_Node{
	string Q;
	string pilihan[4]; 
	char A;
	QA_Node* next;
};//Struct untuk menyimpan pertanyaan, opsi pilihan, serta jawaban masing masing pertanyaan

//array yang berisi pertanyaan untuk mode kuis dari struct QA
QA_Node qa[] = {
    {"Planet mana yang dikenal sebagai 'planet merah'?", {"a) Venus", "b) Mars", "c) Jupiter", "d) Uranus"}, 'b'},
    {"Berapa usia planet Bumi?", {"a) 4,5 miliar tahun", "b) 4,6 miliar tahun", "c) 5 miliar tahun", "d) 3,5 miliar tahun"}, 'a'},
    {"Planet apa yang memiliki jarak dari Bumi sebesar 77 juta km?", {"a) Venus", "b) Bumi", "c) Merkurius", "d) Mars"}, 'c'},
    {"Planet terbesar di tata surya adalah:", {"a) Saturnus", "b) Jupiter", "c) Uranus", "d) Neptunus"}, 'b'},
    {"Berapa jarak Venus dari Matahari?", {"a) 108,2 juta km", "b) 149,6 juta km", "c) 227,9 juta km", "d) 57,9 juta km"}, 'a'},
    {"Warna apa yang menggambarkan Uranus?", {"a) Merah", "b) Biru kehijauan", "c) Kuning keemasan", "d) Coklat-kuning"}, 'b'},
    {"Planet yang dikenal dengan cincinnya yang spektakuler adalah:", {"a) Jupiter", "b) Saturnus", "c) Uranus", "d) Neptunus"}, 'b'},
    {"Planet mana yang memiliki luas permukaan sebesar 510,1 juta km^2?", {"a) Bumi", "b) Mars", "c) Venus", "d) Merkurius"}, 'a'},
    {"Neptunus memiliki jarak dari Bumi sebesar:", {"a) 4,5 miliar km", "b) 4,6 miliar km", "c) 4,3 miliar km", "d) 4,2 miliar km"}, 'a'},
    {"Warna Merkurius adalah:", {"a) Kuning terang", "b) Biru kebiruan", "c) Abu-abu kehitaman", "d) Merah"}, 'c'},
    {"Planet kedua terdekat dari Matahari adalah:", {"a) Bumi", "b) Mars", "c) Venus", "d) Jupiter"}, 'c'},
    {"Berapa luas permukaan Saturnus?", {"a) 42,7 miliar km^2", "b) 61,4 miliar km^2", "c) 144,8 juta km^2", "d) 74,8 juta km^2"}, 'a'},
    {"Berapa usia planet Jupiter?", {"a) 4,6 miliar tahun", "b) 4,5 miliar tahun", "c) 4,7 miliar tahun", "d) 4,4 miliar tahun"}, 'b'},
    {"Planet yang terkenal dengan rotasi yang ekstrem adalah:", {"a) Uranus", "b) Neptunus", "c) Saturnus", "d) Mars"}, 'a'},
    {"Bumi memiliki jarak dari Matahari sebesar:", {"a) 108,2 juta km", "b) 227,9 juta km", "c) 149,6 juta km", "d) 778,5 juta km"}, 'c'},
    {"Planet mana yang memiliki luas permukaan 8,1 miliar km^2?", {"a) Uranus", "b) Saturnus", "c) Neptunus", "d) Jupiter"}, 'a'},
    {"Warna Jupiter adalah:", {"a) Biru kehijauan", "b) Coklat-kuning", "c) Kuning terang", "d) Abu-abu kehitaman"}, 'b'},
    {"Berapa jarak Mars dari Matahari?", {"a) 57,9 juta km", "b) 149,6 juta km", "c) 227,9 juta km", "d) 778,5 juta km"}, 'c'},
    {"Planet terdekat dari Matahari adalah:", {"a) Mars", "b) Venus", "c) Merkurius", "d) Jupiter"}, 'c'},
    {"Berapa usia planet Uranus?", {"a) 4,5 miliar tahun", "b) 4,6 miliar tahun", "c) 4,4 miliar tahun", "d) 4,3 miliar tahun"}, 'a'},
    {"Neptunus memiliki warna:", {"a) Biru kebiruan", "b) Kuning keemasan", "c) Merah", "d) Coklat-kuning"}, 'a'},
    {"Planet mana yang memiliki luas permukaan sebesar 144,8 juta km^2?", {"a) Mars", "b) Bumi", "c) Venus", "d) Merkurius"}, 'a'},
    {"Planet yang dikenal sebagai 'planet kedua terdekat dari Matahari' adalah:", {"a) Mars", "b) Venus", "c) Merkurius", "d) Bumi"}, 'b'},
    {"Berapa jarak Saturnus dari Bumi?", {"a) 1,4 miliar km", "b) 2,9 miliar km", "c) 4,5 miliar km", "d) 778 juta km"}, 'a'},
    {"Planet mana yang dikenal dengan warna biru kebiruan?", {"a) Uranus", "b) Neptunus", "c) Jupiter", "d) Saturnus"}, 'b'}
};

//array yang berisi data data setiap planet dari struct planet 
Planet planet[14] = {
    {{"Merkurius", "4,6 miliar tahun", "77 juta km", "57,9 juta km", "Abu-abu kehitaman", "74,8 juta km^2", "Planet terdekat dari Matahari"}},
    {{"Venus", "4,5 miliar tahun", "41 juta km", "108,2 juta km", "Kuning terang", "460,2 juta km^2", "Planet kedua terdekat dari Matahari"}},
    {{"Bumi", "4,5 miliar tahun", "0 km", "149,6 juta km", "Beragam", "510,1 juta km^2", "Tempat tinggal kita!"}},
    {{"Mars", "4,6 miliar tahun", "225 juta km", "227,9 juta km", "Merah", "144,8 juta km^2", "Planet yang dikenal sebagai 'planet merah'"}},
    {{"Jupiter", "4,5 miliar tahun", "778 juta km", "778,5 juta km", "Coklat-kuning", "61,4 miliar km^2", "Planet terbesar di tata surya"}},
    {{"Saturnus", "4,5 miliar tahun", "1,4 miliar km", "1,4 miliar km", "Kuning keemasan", "42,7 miliar km^2", "Dikenal dengan cincinnya yang spektakuler"}},
    {{"Uranus", "4,5 miliar tahun", "2,9 miliar km", "2,9 miliar km", "Biru kehijauan", "8,1 miliar km^2", "Terkenal dengan rotasi yang ekstrem"}},
    {{"Neptunus", "4,5 miliar tahun", "4,5 miliar km", "4,5 miliar km", "Biru kebiruan", "7,6 miliar km^2", "Planet paling jauh dari Matahari dalam tata surya kita"}},
    {{"Pluto", "4,6 miliar tahun", "5,9 miliar km", "5,9 miliar km", "Coklat kekuningan", "16,6 juta km^2", "Planet katai di Sabuk Kuiper"}},
    {{"Matahari", "4,6 miliar tahun", "149,6 juta km", "0 km", "Kuning-putih", "6,09 x 10^12 km^2", "Bintang pusat tata surya"}},
    {{"Ceres", "4,6 miliar tahun", "413 juta km", "413 juta km", "Abu-abu", "2,77 juta km^2", "Planet katai di Sabuk Asteroid"}},
    {{"Haumea", "4,6 miliar tahun", "6,4 miliar km", "6,4 miliar km", "Putih", "5,9 juta km^2", "Planet katai dengan bentuk lonjong di Sabuk Kuiper"}},
    {{"Makemake", "4,6 miliar tahun", "6,85 miliar km", "6,85 miliar km", "Coklat kemerahan", "14,3 juta km^2", "Planet katai di Sabuk Kuiper"}},
    {{"Eris", "4,6 miliar tahun", "10,1 miliar km", "10,1 miliar km", "Putih", "17,8 juta km^2", "Planet katai terjauh di Sabuk Kuiper"}}
};

//array dari beberapa nama file yang digunakan sebagai teks penjelasan di mode belajar
string filename[14] = {"Merkurius.txt", "Venus.txt", "Bumi.txt", "Mars.txt", "Jupiter.txt", "Saturnus.txt", "Uranus.txt", "Neptunus.txt", "Pluto.txt", "Matahari.txt", "Ceres.txt", "Haumea.txt", "Makemake.txt", "Eris.txt"};
    
//pembagian fungsi
/// (1). fungsi non krusial (fungsi yang tidak berpengaruh banyak pada sistem utama alias fungsi pendukung) 
void menu();
void kredit (){
	cout << "created by : \n";
	cout << "Ai'nur Azizah\n";
	cout << "Novita Enggelina Turnip\n";
	cout << "Muhammad Arif Syafitra\n";
	cout << "Rehandra\n";
}

void banner(){
	cout << "===============================================" << endl;
	cout << "|                SELAMAT DATANG               |" << endl;
	cout << "===============================================" << endl;
	cout << endl << endl;
}

void keluar(){
	cout << "Terima kasih telah berkunjung\n";
	cout << "Sampai jumpa lagi !!!";
}

void heading(){
	cout << "===============================================" << endl;
	cout << "|                   BELAJAR                   |" << endl;
	cout << "===============================================" << endl;
	cout << endl << endl;
}

void Headpilih(){
	cout << "===============================================" << endl;
	cout << "|                 PILIH MODE                   |" << endl;
	cout << "===============================================" << endl;
	cout << endl << endl;
}

void opening(){
	banner();
	kredit();
	sleep(3);
	system("cls");
	banner();
	cout << "Selamat datang di aplikasi OurPlanets" << endl;
	sleep(3);
	system("cls");
	banner();
	cout << "Aplikasi ini akan membimbing kamu untuk mengetahui beberapa hal dasar\nmengenai planet planet yang ada di tata surya kita. Aplikasi ini\n";
	cout << "terdiri dari 2 buah mode yaitu mode belajar dan mode kuis.\nkami berharap pengguna mendapatkan sedikit wawasan lewat aplikasi ini\n";
	cout << "SELAMAT MENCOBA" << endl;
}

void qHead(){
	cout << "===============================================" << endl;
	cout << "|                     QUIZ                    |" << endl;
	cout << "===============================================" << endl;
	cout << endl << endl;
}

void openingQ(){
	cout << "Selamat datang di mode quiz\n";
	cout << "di mode ini kamu akan menjawab total 10 buah soal bertipe objektif yang dipilih secara acak oleh sistem\n";
	cout << "nilai beserta rinican jawaban akan ditampilkan setelah kamu menjawab semua soal\n";
	cout << "SELAMAT MENGERJAKAN";
}

// Fungsi krusial atau fungsi yang sangat berpengatuh untuk berjalannya program

void tukar(QA_Node& a, QA_Node& b) {  // Fungsi untuk menukar dua elemen dalam array QA_Node
    QA_Node temp = a;
    a = b;
    b = temp;
}

void tampilkanDataPlanet(Planet p, const string keterangan[], const string filename[]) { //Fungsi untuk menampilkan file .txt dan ringkasasn
	system("cls");                                                          
    heading();
    for (int i = 0; i < 14; i++) {
    	ifstream file(filename[i].c_str());
  		if (p.data[0] + ".txt" == filename[i]){
  		string line;
    	while (getline(file, line)) {
       	cout << line << endl;
    		}
		}
    	file.close();
	}	
	cout << endl << endl;
	cout << "------Rangkuman------\n" << endl;
	for (int i = 0; i < MAX; i++){
		cout << keterangan[i] << " = " << p.data[i] << endl;
	}
}

void tambahkanNode(QA_Node*& head, string question, string options[], char answer) {// Fungsi untuk membuat dam Menambahkan node baru di akhir linked list
    QA_Node* newNode = new QA_Node;
    newNode->Q = question;
    for (int i = 0; i < 4; ++i) {
        newNode->pilihan[i] = options[i];
    }
    newNode->A = answer;
    newNode->next = NULL;
    
    if (!head) {
        head = newNode;
    } else {
        QA_Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

string toLowerCase(string str) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            // Konversi karakter ke huruf kecil jika karakter adalah huruf besar agar data di fitur cari planet tetap sesuai
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

void cariPlanet(const Planet planet[], const string keterangan[], const string filename[]) {// Fungsi untuk melakukan pencarian data planet berdasarkan nama
    string namaPlanet;
    cout << "Terdapat beberapa planet atau bintang tambahan : Matahari, Pluto, Ceres,\nEris, Haumea, Makemake" << endl;
    cout << "Masukkan nama planet yang ingin Anda ketahui: ";
    cin.ignore(); // Membersihkan buffer sebelum membaca input
    getline(cin, namaPlanet);
    string masukan = namaPlanet;
    string keluaran = toLowerCase(masukan);
    
    bool found = false;
    for(int i = 0; i < 14; ++i){
    	string namaPlanetArray = toLowerCase(planet[i].data[0]); //untuk memastikan bahwa input diubah ke huruf kecil
    	if (planet[i].data[0] == namaPlanet || namaPlanetArray == keluaran) { // mencari planet sesuai dengan apa yang diinput
	        tampilkanDataPlanet(planet[i], keterangan, filename);// Mengembalikan indeks planet jika ditemukan
	        found = true;
	        break;
    		}
		}
		if(!found){
			cout << "planet tidak ditemukan!" << endl;
		}
	}

int partisi(QA_Node arr[], int low, int high) { // Fungsi partisi untuk quicksort
    string pivot = arr[high].Q;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].Q < pivot) {
            i++;
            tukar(arr[i], arr[j]);
        }
    }
    tukar(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort(QA_Node arr[], int low, int high) { // Fungsi quicksort rekursif untuk mengurutkan array QA_Node
    if (low < high) {
        int pi = partisi(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

//mekanisme quis
void quis(QA_Node* head) {
  system("cls");
  qHead();
  vector<int> qaDipilih;
  srand(time(0));
  QA_Node* temp = head;
  vector<QA_Node*> questions;
  while (temp) {
    questions.push_back(temp);
    temp = temp->next;
  }
  while (qaDipilih.size() < 10) {
    int index = rand() % questions.size();
    if (find(qaDipilih.begin(), qaDipilih.end(), index) == qaDipilih.end()) {
      qaDipilih.push_back(index);
    }
  }
  int score = 0;
  for (int i = 0; i < 10; ++i) {
    int index = qaDipilih[i];
    char jawaban;
    bool valid = false;
    while (!valid) {
      cout << "Pertanyaan " << i + 1 << ": " << questions[index]->Q << endl;
      for (int j = 0; j < 4; ++j) {
        cout << questions[index]->pilihan[j] << endl;
      }
      cout << "Jawaban Anda (a, b, c, d): ";
      cin >> jawaban;
      // Validasi input
      jawaban = tolower(jawaban);
      if (jawaban >= 'a' && jawaban <= 'd') {
        valid = true;
      } else {
        cout << "Input tidak valid. Silakan masukkan a, b, c, atau d." << endl;
      }
    }
    // Cek jawaban
    if (jawaban == questions[index]->A) {
      score++;
      cout << "Jawaban Anda benar!" << endl;
    } else {
      cout << "Jawaban Anda salah. Jawaban yang benar adalah " << questions[index]->A << "." << endl;
    }
    cout << endl;
    sleep(1); // Tambahkan jeda untuk memberi waktu pengguna membaca
  }
  // Menampilkan skor akhir
  cout << "Quiz selesai!" << endl;
  cout << "Skor Anda: " << score << " dari 10" << endl;
  bool quislanjut = false;
  char quisLanjut;
  while (!quislanjut){
  	cout << "Ulang bermain(Y/N) : ";
  cin >> quisLanjut;
  switch (quisLanjut) {
  case 'Y':
  case 'y':
  	quislanjut = true;
    quis(head); // Panggil fungsi rekursif
    break;
  case 'N':
  case 'n':
  	quislanjut = true;
    system("cls");
    menu();
    break;
  default:
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Input salah masukkan input yang benar\n";
    sleep(1);
    continue;
  		}
 	 }
}

void belajar(int mode);

const int numQuestions = sizeof(qa) / sizeof(qa[0]);

void menu() {
  system("cls"); // Bersihkan layar
  Headpilih(); // Cetak header menu
  int mode; // Deklarasikan variabel untuk mode pilihan
  QA_Node* head = NULL; // Inisialisasi head pointer untuk linked list
  cout << "Mode yang tersedia:\n"; // Tampilkan menu mode
  cout << "1. Belajar\n";
  cout << "2. Quiz\n";
  cout << "3. Keluar\n";
  cout << "Pilih mode: ";
  cin >> mode; // Dapatkan input mode dari pengguna
  switch (mode) {
    case 1: // Mode Belajar
      system("cls"); // Bersihkan layar
      heading(); // Cetak header mode belajar
      belajar(mode); // Jalankan fungsi belajar
      break;
    case 2: // Mode Quiz
      system("cls"); // Bersihkan layar
      qHead(); // Cetak header mode quiz
      sleep(0.5); // Berikan jeda singkat
      openingQ(); // Tampilkan pesan pembuka quiz
      sleep(3.5); // Berikan jeda 4 detik
      if (!head) { // Periksa apakah head sudah diinisialisasi
        // Jika belum, buat linked list pertanyaan quiz
        head = NULL; // Reset head menjadi NULL
        for (int i = 0; i < numQuestions; ++i) {
          tambahkanNode(head, qa[i].Q, qa[i].pilihan, qa[i].A);
        }
      }
      quis(head); // Panggil fungsi quiz dengan linked list yang sudah dibuat
      break;
    case 3: // Mode Keluar
      system("cls"); // Bersihkan layar
      keluar(); // Cetak pesan keluar
      exit(0); // Keluar dari program
    default: // Input tidak valid
      cin.clear(); // Hapus status error input
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Abaikan input yang salah
      cout << "Input tidak valid. Silakan masukkan angka 1, 2, atau 3." << endl;
      sleep(1); // Berikan jeda singkat
      menu();
	  break; // Kembali ke awal menu
  }
  // Bebaskan memori yang dialokasikan untuk linked list
  if (mode != 3) {
    QA_Node* temp = head;
    QA_Node* next;
    while (temp) {
      next = temp->next;
      delete temp;
      temp = next;
    }
  }
}

void lanjutBelajar(){
	char lanjut;
	bool validInput = false;
        while (!validInput) {
            sleep(0.5);
            cout << endl;
            cout << "Lanjut belajar? (y/n) : ";
            cin >> lanjut;
            switch (lanjut) {
                case 'Y': case 'y':
                	system("cls");
                    validInput = true;
                    belajar(0);
                    break;
                case 'N': case 'n':
                    system("cls");
                    menu();
                    return; // Keluar dari fungsi belajar
                default:
                    cin.clear(); // Menghapus state kesalahan
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input yang salah
                    cout << "Input invalid\n";
                    cout << "Masukkan input yang benar.\n";
                    sleep(1); // Memberi jeda sebelum meminta input lagi
                    continue;
            }
        }
}

void belajar(int mode){
    string keterangan[MAX] = {"Nama", "Usia", "Jarak dari Bumi", "Jarak dari Matahari", "Warna", "Luas", "Status"};
    int pilih;
    while (true) {
        system("cls");
        heading();
        cout << "Dalam tata surya kita total ada 8 planet, mereka semua memiliki\nposisi masing-masing dan semuanya bergerak melingkari matahari.\n";
        cout << "Berikut adalah daftar nama-nama planetnya : \n";
        cout << "1. Merkurius\n";
        cout << "2. Venus\n";
        cout << "3. Bumi\n";
        cout << "4. Mars\n";
        cout << "5. Jupiter\n";
        cout << "6. Saturnus\n";
        cout << "7. Uranus\n";
        cout << "8. Neptunus\n";
        cout << "9. Lainnya\n";
        cout << "10. Kembali\n";
        cout << "Pilih planet yang ingin anda ketahui (1-9) : ";
        cin >> pilih;
        switch (pilih) {
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
            	tampilkanDataPlanet(planet[pilih - 1], keterangan, filename);
                lanjutBelajar();
                break;
            case 9:
                cariPlanet(planet, keterangan, filename);
                lanjutBelajar();
                break;
            case 10:
                menu();
                break;
            default:
            	cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Abaikan input yang salah
                cout << "Input tidak valid. Silakan masukkan angka 1-9." << endl;
                sleep(1);
                continue; // Kembali ke awal menu
        }break;
    }
}

int main() {
	cout << "\033]0;" << "OurPlanets" << "\007";
    char siap;
    opening();
    quicksort(qa, 0, numQuestions - 1);
    while (true) {
        cout << "Apakah kamu siap? (Y/N) : ";
        cin >> siap;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');        // Abaikan sisa karakter dalam input buffer
        switch (siap) {
            case 'Y':
            case 'y':
                system("cls");
                menu();
                break;
            case 'N':
            case 'n':
                system("cls");
                keluar();
                exit(0);
            default:
                cout << "Input salah. Masukkan input yang benar (Y/N)." << endl;
                continue;  // Mengulangi loop untuk meminta input yang benar
        }
        // Jika input valid ('Y' atau 'N'), keluar dari loop
        break;
    }
    return 0;
}
