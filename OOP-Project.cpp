#include <iostream>
#include <string> 
using namespace std;

class PhuongTien {
protected:
    string id;
    string hangXe;
    int namSanXuat;
    int tinhTrang; 
public:
    virtual void nhapThongTin(); 
    virtual void hienThiThongTin();
	void setTinhTrang(int tt){
		tinhTrang = tt;
	}
    string getID() {
        return id;
    }

    int getTinhTrang() {
        return tinhTrang;
    }
};

void PhuongTien::nhapThongTin() {
	 cout << "Nhap hang xe: ";
    getline(cin, hangXe);
    cout << "Nhap ID xe: ";
    getline(cin, id);
    cout << "Nhap nam san xuat: ";
    cin >> namSanXuat; cin.ignore();
    do {
        cout << "Nhap tinh trang (0: chua thue, 1: da thue): ";
        cin >> tinhTrang; cin.ignore();
        if (tinhTrang != 0 && tinhTrang != 1) {
            cout << "Tinh trang khong hop le! Vui long nhap lai." << endl;
        }
    } while (tinhTrang != 0 && tinhTrang != 1);
}

void PhuongTien::hienThiThongTin() {
	cout << "\n___________________________________" << endl; 
    cout <<"\nHang xe: " << hangXe << "\nID: " << id << "\nNam san xuat: " << namSanXuat << "\nTinh trang: " << (tinhTrang == 0 ? "Chua thue" : "Da thue") << endl;
}

class XeMay : public virtual PhuongTien {
private:
    int congSuat;
public:
    void nhapThongTin()  {
        PhuongTien::nhapThongTin();
        cout << "Nhap cong suat: ";
        cin >> congSuat; cin.ignore();
    }

    void hienThiThongTin() {
        PhuongTien::hienThiThongTin();
        cout << "Cong suat: " << congSuat << "cc" << endl;
    }
};

class Oto : public virtual PhuongTien {
private:
    int soCho;
public:
    void nhapThongTin()  {
        PhuongTien::nhapThongTin();
        cout << "Nhap so cho: ";
        cin >> soCho; cin.ignore();
    }

    void hienThiThongTin() {
        PhuongTien::hienThiThongTin();
        cout << "So cho: " << soCho << endl;
    }
};

class QLPT {
private:
    PhuongTien* danhSachPhuongTien[100];
    int soLuongPhuongTien;
public:
    QLPT() : soLuongPhuongTien(0) {}
    
    void capNhatPhuongTien(const string& id) {
    for (int i = 0; i < soLuongPhuongTien; ++i) {
        if (danhSachPhuongTien[i]->getID() == id) {
            cout << "Cap nhat thong tin cho phuong tien: " << id << endl;
            danhSachPhuongTien[i]->nhapThongTin();
            cout << "Da cap nhat thong tin!" << endl;
            return;
        }
    }
    cout << "Khong tim thay phuong tien de cap nhat!" << endl;
}
	void capNhatTinhTrang(const string& id) {
    for (int i = 0; i < soLuongPhuongTien; ++i) {
        if (danhSachPhuongTien[i]->getID() == id) {
            int tinhTrangMoi;
            cout << "Nhap tinh trang moi (0: chua thue, 1: da thue): ";
            cin >> tinhTrangMoi;
return ;
        }
    }
}
    void traXe(const string& id) {
    for (int i = 0; i < soLuongPhuongTien; ++i) {
        if (danhSachPhuongTien[i]->getID() == id) {
        	if (danhSachPhuongTien[i]->getTinhTrang() == 1) {
                danhSachPhuongTien[i]->setTinhTrang(0);
                cout << "Da tra xe: " << id << endl;
            } else {
                cout << "Xe " << id << " hien tai chua duoc thue." << endl;
            }
            return;
        }
    }
    cout << "Khong tim thay xe co ten: " << id << endl;
    cout << "Khong tim thay phuong tien de cap nhat!" << endl;
};

    void themPhuongTien(PhuongTien* pt) {
        if (soLuongPhuongTien < 100) {
            danhSachPhuongTien[soLuongPhuongTien++] = pt;
        } else {
            cout << "Danh sach phuong tien da day!" << endl;
        }
    }

    void timKiemTenXe(const string& id) {
        for (int i = 0; i < soLuongPhuongTien; ++i) {
            if (danhSachPhuongTien[i]->getID() == id) {
                danhSachPhuongTien[i]->hienThiThongTin();
                return;
            }
        }
        cout << "Khong tim thay phuong tien co ID: " << id << endl;
    }

    void hienThiDanhSach() {
        for (int i = 0; i < soLuongPhuongTien; ++i) {
            danhSachPhuongTien[i]->hienThiThongTin();
            cout << "\n___________________________________" << endl; 
        }
    }

    void xoaPhuongTien(const string& id) {
        for (int i = 0; i < soLuongPhuongTien; ++i) {
            if (danhSachPhuongTien[i]->getID() == id) {
for (int j = i; j < soLuongPhuongTien - 1; ++j) {
                    danhSachPhuongTien[j] = danhSachPhuongTien[j + 1];
                }
                --soLuongPhuongTien;
                cout << "Da xoa phuong tien " << id << endl;
                return;
            }
        }
        cout << "Khong tim thay phuong tien de xoa!" << endl;
    }
};

int main() {
    QLPT qlpt;
    int luaChon;

    do {
        cout << "___________________________________" << endl; 
        cout << "|             MENU:               |" << endl;
        cout << "| 1. Them moi phuong tien         |" << endl;
        cout << "| 2. Tim kiem phuong tien theo ID |" << endl;
        cout << "| 3. Hien thi danh sach xe        |" << endl;
        cout << "| 4. Xoa phuong tien              |" << endl;
        cout << "| 5. Sua thong tin phuong tien    |" << endl;
        cout << "| 6. Cap nhat tinh trang          |" << endl;
        cout << "| 7. Thoat                        |" << endl;
        cout << "|_________________________________|" << endl; 
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        if (luaChon == 1) {
            PhuongTien* phuongTien;
            int loaiPhuongTien;

            cout << "Chon loai phuong tien (1-Xe may, 2-Oto): ";
            cin >> loaiPhuongTien;
            cin.ignore();

            if (loaiPhuongTien == 1) {
                phuongTien = new XeMay();
            } else if (loaiPhuongTien == 2) {
                phuongTien = new Oto();
            } else {
            	cout << "Lua chon khong hop le!" << endl;
                continue;
            }

            phuongTien->nhapThongTin();
            qlpt.themPhuongTien(phuongTien);
        } else if (luaChon == 2) {
            string tenXe;
            cout << "Nhap ID phuong tien can tim: ";
            getline(cin, tenXe);
            qlpt.timKiemTenXe(tenXe);
        } else if (luaChon == 3) {
            qlpt.hienThiDanhSach();
        } else if (luaChon == 4) {
            string tenXe;
            cout << "Nhap ID phuong tien can xoa: ";
            getline(cin, tenXe);
            qlpt.xoaPhuongTien(tenXe);
        } else if (luaChon == 5) {
        	
		} else if (luaChon == 6) {
			
		} 
    } while (luaChon != 7);

    return 0;
}
