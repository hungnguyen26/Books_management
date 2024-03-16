#include <iostream>
#include <vector>
using namespace std;
class SACH
{
    public:
        string tensach;
        string tacgia;
        string namxuatban;
        double giatien;
        SACH()
        {
        	tensach=" ";
        	tacgia=" ";
        	namxuatban=" ";
        	giatien=0.0;
		}
    virtual void input()
    {
        cout<<"\n Nhap ten sach: ";
        cin.ignore();
        getline(cin,tensach);
        cout<<"\n Nhap ten tac gia: ";
        cin.ignore();
        getline(cin,tacgia);
        cout<<"\n Nhap nam xuat ban (dd/mm/yyyy): ";
        cin.ignore();
        getline(cin,namxuatban);


    };
    virtual void output()
    {
        cout<<"\n Ten sach: "<<tensach;
        cout<<"\n Ten tac gia: "<<tacgia;
        cout<<"\n Nam xuat ban (dd/mm/yyyy) : "<<namxuatban;
    };
    virtual double tinhtien()=0;
    
    
};
class SACHGIAOKHOA:public SACH
{
    public:
        string monhoc;
    SACHGIAOKHOA(): SACH()
    {
    	monhoc=" ";
	}
    void input()
    {
        SACH::input();
        cout<<"\n \n Nhap mon hoc: ";
        getline(cin,monhoc);
        cout<<"\n Nhap gia tien: ";
        cin>>giatien;
    };
    void output()
    {
        SACH::output();
        cout<<"\n Mon hoc: "<<monhoc;
        cout<<"\n Gia tien: "<<giatien;
    };
    double tinhtien()
    {
    	double vat= giatien*0;
        return giatien+ vat;
    };
  
};
class TIEUTHUYET: public SACH
{
    public:
        string theloai;
        TIEUTHUYET(): SACH()
        {
        	theloai=" ";
		}
        void input()
        {
            SACH::input();
            cout<<"\n Nhap the loai:";
            getline(cin,theloai);
            cout<<"\n Nhap gia tien: ";
        	cin>>giatien;
        };
        void output()
        {
            SACH::output();
            cout<<"\n The loai: "<<theloai;
            cout<<"\n Gia tien: "<<giatien;
        };
        double tinhtien()
        {
         	double vat= giatien*0.1;
       		return giatien+ vat;
        };
};
class SACHTHAMKHAO: public SACH
{
	public:
		string chude;
	SACHTHAMKHAO(): SACH()
	{
		chude=" ";
	}
	void input()
        {
            SACH::input();
            cout<<"\n Nhap chu de:";
            getline(cin,chude);
            cout<<"\n Nhap gia tien: ";
        	cin>>giatien;
        };
    void output()
        {
            SACH::output();
            cout<<"\n Chu de: "<<chude;
            cout<<"\n Gia tien: "<<giatien;
        };
    double tinhtien()
        {
            double vat= giatien*0.05;
       		return giatien+ vat;
        };
};
class TRUYENTRANH: public SACH
{
	public:
		string phongcach;
		TRUYENTRANH(): SACH()
		{
			phongcach=" ";
		}
		void input()
        {
            SACH::input();
            cout<<"\n Nhap phong cach:";
            getline(cin,phongcach);
            cout<<"\n Nhap gia tien: ";
        	cin>>giatien;
        };
        void output()
        {
            SACH::output();
            cout<<"\n Phong cach "<<phongcach;
            cout<<"\n Gia tien: "<<giatien;
        };
        double tinhtien()
        {
             double vat= giatien*0.05;
       		return giatien+ vat;
        };	
};
class THIEUNHI: public SACH
{
	public:
		string dotuoi;
		THIEUNHI():SACH()
		{
			dotuoi=0.0;
		}
		void input()
        {
            SACH::input();
            cout<<"\n Nhap do tuoi phu hop:";
            getline(cin,dotuoi);
            cout<<"\n Nhap gia tien: ";
        	cin>>giatien;
        };
        void output()
        {
            SACH::output();
            cout<<"\n Do tuoi phu hop: "<<dotuoi;
            cout<<"\n Gia tien: "<<giatien;
        };
        double tinhtien()
        {
             double vat= giatien*0.05;
       		return giatien+ vat;
        };	
};
class Thuvien
{
    public:
        vector<SACHGIAOKHOA> ds_sachgiaokhoa;
        vector<TIEUTHUYET> ds_tieuthuyet; 
        vector<SACHTHAMKHAO> ds_sachthamkhao;
        vector<TRUYENTRANH> ds_truyentranh;
        vector<THIEUNHI> ds_thieunhi;
    void input()
    {
    	system("cls");
        int chon;
        while(true)
        {
            cout<<"\n\n\t\t============   MENU  ============";
            cout<<"\n\t 1.Sach giao khoa ";
            cout<<"\n\t 2.Tieu Thuyet ";
            cout<<"\n\t 3.Sach tham khao ";
            cout<<"\n\t 4.Truyen tranh ";
            cout<<"\n\t 5.Thieu nhi ";
            cout<<"\n\t 6.Tim kiem sach ";
            cout<<"\n\t 7.Chinh sua thong tin sach ";
            cout<<"\n\t 8.Xoa sach ";
            cout<<"\n\t 9.Thong ke sach ";
            cout<<"\n\t 0.Thoat ";
            cout<<"\n\n\t\t=============   END  ============";
            cout<<"\n Nhap lua chon:";
            cin>>chon;
            if(chon==1)
            {
                SACHGIAOKHOA x;
                cout<<"\n\n\t\t NHAP THONG TIN SACH GIAO KHOA \n";
                x.input();
                ds_sachgiaokhoa.push_back(x);
            }
            else if(chon==2)
            {
                TIEUTHUYET x;
                cout<<"\n\n\t\t NHAP THONG TIN TIEU THUYET \n";
                x.input();
                ds_tieuthuyet.push_back(x);
            }
            else if(chon==3)
            {
                SACHTHAMKHAO x;
                cout<<"\n\n\t\t NHAP THONG TIN SACH THAM KHAO \n";
                x.input();
                ds_sachthamkhao.push_back(x);
            }
            else if(chon==4)
            {
                TRUYENTRANH x;
                cout<<"\n\n\t\t NHAP THONG TIN TRUYEN TRANH \n";
                x.input();
                ds_truyentranh.push_back(x);
            }
            else if(chon==5)
            {
                THIEUNHI x;
                cout<<"\n\n\t\t NHAP THONG TIN SACH THIEU NHI \n";
                x.input();
                ds_thieunhi.push_back(x);
            }
            else if (chon == 6)
            {
                cin.ignore();
                string tensach;
                cout << "\n\n\t\t NHAP TEN SACH CAN TIM: ";
                getline(cin, tensach);
                timkiem(tensach);
            }
            else if (chon == 7)
            {
                cin.ignore();
                string tensach;
                cout << "\n\n\t\t NHAP TEN SACH CAN CHINH SUA: ";
                getline(cin, tensach);
                chinhsua(tensach);
            }
            else if (chon == 8)
            {
                cin.ignore();
                string tensach;
                cout << "\n\n\t\t NHAP TEN SACH CAN XOA: ";
                getline(cin, tensach);
                xoa(tensach);
            }
            else if (chon == 9)
            {
                thongKe();
            }

            else if(chon==0)
            {
                break;
            }
            else{
                cout<<"\n Lua chon khong hop le, vui long kiem tra lai !! ";
            }
        } 
    };
    void timkiem(string tensach)
    {
        bool found = false;
        // Tìm kiếm trong danh sách sách giáo khoa
        for (int i = 0; i < ds_sachgiaokhoa.size(); i++)
        {
            if (ds_sachgiaokhoa[i].tensach == tensach)
            {
                cout << "\n\n\t\t TIM THAY SACH GIAO KHOA CO TEN: " << tensach;
                ds_sachgiaokhoa[i].output();
                found = true;
            }
        }
        // Tìm kiếm trong danh sách tiểu thuyết
        for (int i = 0; i < ds_tieuthuyet.size(); i++)
        {
            if (ds_tieuthuyet[i].tensach == tensach)
            {
                cout << "\n\n\t\t TIM THAY TIEU THUYET CO TEN: " << tensach;
                ds_tieuthuyet[i].output();
                found = true;
            }
        }
        // Tìm kiếm trong danh sách sách tham khảo
        for (int i = 0; i < ds_sachthamkhao.size(); i++)
        {
            if (ds_sachthamkhao[i].tensach == tensach)
            {
                cout << "\n\n\t\t TIM THAY SACH THAM KHAO CO TEN: " << tensach;
                ds_sachthamkhao[i].output();
                found = true;
            }
        }
        // Tìm kiếm trong danh sách truyện tranh
        for (int i = 0; i < ds_truyentranh.size(); i++)
        {
            if (ds_truyentranh[i].tensach == tensach)
            {
                cout << "\n\n\t\t TIM THAY TRUYEN TRANH CO TEN: " << tensach;
                ds_truyentranh[i].output();
                found = true;
            }
        }
        // Tìm kiếm trong danh sách sách thiếu nhi
        for (int i = 0; i < ds_thieunhi.size(); i++)
        {
            if (ds_thieunhi[i].tensach == tensach)
            {
                cout << "\n\n\t\t TIM THAY SACH THIEU NHI CO TEN: " << tensach;
                ds_thieunhi[i].output();
                found = true;
            }
        }
        if (!found)
        {
            cout << "\n\n\t\t KHONG TIM THAY SACH CO TEN: " << tensach;
        }
    }
    void chinhsua(string tensach)
    {
        bool found = false;
        // Chỉnh sửa trong danh sách sách giáo khoa
        for (int i = 0; i < ds_sachgiaokhoa.size(); i++)
        {
            if (ds_sachgiaokhoa[i].tensach == tensach)
            {
                cout << "\n\n\t\t CHINH SUA THONG TIN SACH GIAO KHOA CO TEN: " << tensach;
                ds_sachgiaokhoa[i].input();
                found = true;
            }
        }
        // Chỉnh sửa trong danh sách tiểu thuyết
        for (int i = 0; i < ds_tieuthuyet.size(); i++)
        {
            if (ds_tieuthuyet[i].tensach == tensach)
            {
                cout << "\n\n\t\t CHINH SUA THONG TIN TIEU THUYET CO TEN: " << tensach;
                ds_tieuthuyet[i].input();
                found = true;
            }
        }
        // Chỉnh sửa trong danh sách sách tham khảo
        for (int i = 0; i < ds_sachthamkhao.size(); i++)
        {
            if (ds_sachthamkhao[i].tensach == tensach)
            {
                cout << "\n\n\t\t CHINH SUA THONG TIN SACH THAM KHAO CO TEN: " << tensach;
                ds_sachthamkhao[i].input();
                found = true;
            }
        }
        // Chỉnh sửa trong danh sách truyện tranh
        for (int i = 0; i < ds_truyentranh.size(); i++)
        {
            if (ds_truyentranh[i].tensach == tensach)
            {
                cout << "\n\n\t\t CHINH SUA THONG TIN TRUYEN TRANH CO TEN: " << tensach;
                ds_truyentranh[i].input();
                found = true;
            }
        }
        // Chỉnh sửa trong danh sách sách thiếu nhi
        for (int i = 0; i < ds_thieunhi.size(); i++)
        {
            if (ds_thieunhi[i].tensach == tensach)
            {
                cout << "\n\n\t\t CHINH SUA THONG TIN SACH THIEU NHI CO TEN: " << tensach;
                ds_thieunhi[i].input();
                found = true;
            }
        }
        if (!found)
        {
            cout << "\n\n\t\t KHONG TIM THAY SACH CO TEN: " << tensach;
        }
    }
    void xoa(string tensach)
    {
        bool found = false;
        // Xóa trong danh sách sách giáo khoa
        for (int i = 0; i < ds_sachgiaokhoa.size(); i++)
        {
            if (ds_sachgiaokhoa[i].tensach == tensach)
            {
                cout << "\n\n\t\t XOA THONG TIN SACH GIAO KHOA CO TEN: " << tensach;
                ds_sachgiaokhoa.erase(ds_sachgiaokhoa.begin() + i);
                found = true;
                break;
            }
        }
        // Xóa trong danh sách tiểu thuyết
        for (int i = 0; i < ds_tieuthuyet.size(); i++)
        {
            if (ds_tieuthuyet[i].tensach == tensach)
            {
                cout << "\n\n\t\t XOA THONG TIN TIEU THUYET CO TEN: " << tensach;
                ds_tieuthuyet.erase(ds_tieuthuyet.begin() + i);
                found = true;
                break;
            }
        }
        // Xóa trong danh sách sách tham khảo
        for (int i = 0; i < ds_sachthamkhao.size(); i++)
        {
            if (ds_sachthamkhao[i].tensach == tensach)
            {
                cout << "\n\n\t\t XOA THONG TIN SACH THAM KHAO CO TEN: " << tensach;
                ds_sachthamkhao.erase(ds_sachthamkhao.begin() + i);
                found = true;
                break;
            }
        }
        // Xóa trong danh sách truyện tranh
        for (int i = 0; i < ds_truyentranh.size(); i++)
        {
            if (ds_truyentranh[i].tensach == tensach)
            {
                cout << "\n\n\t\t XOA THONG TIN TRUYEN TRANH CO TEN: " << tensach;
                ds_truyentranh.erase(ds_truyentranh.begin() + i);
                found = true;
                break;
            }
        }
        // Xóa trong danh sách sách thiếu nhi
        for (int i = 0; i < ds_thieunhi.size(); i++)
        {
            if (ds_thieunhi[i].tensach == tensach)
            {
                cout << "\n\n\t\t XOA THONG TIN SACH THIEU NHI CO TEN: " << tensach;
                ds_thieunhi.erase(ds_thieunhi.begin() + i);
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "\n\n\t\t KHONG TIM THAY SACH CO TEN: " << tensach;
        }
    }
    void thongKe()
        {
            cout << "\n\n\t\t THONG KE SACH TRONG THU VIEN";
            cout << "\n\n\t\t Tong so luong sach giao khoa: " << ds_sachgiaokhoa.size();
            cout << "\n\n\t\t Tong so luong tieu thuyet: " << ds_tieuthuyet.size();
            cout << "\n\n\t\t Tong so luong sach tham khao: " << ds_sachthamkhao.size();
            cout << "\n\n\t\t Tong so luong truyen tranh: " << ds_truyentranh.size();
            cout << "\n\n\t\t Tong so luong sach thieu nhi: " << ds_thieunhi.size();
        }

    void output()
    {
    	//sgk
    	cout<<"\n\n\t\t ====== DANH SACH SACH GIAO KHOA ======\n";
        for(int i=0;i<ds_sachgiaokhoa.size();i++)
        {
            cout<<"\n\n\t\t THONG TIN SACH GIAO KHOA "<<i+1<<":";
            ds_sachgiaokhoa[i].output();
        }
        //tieu thuyet
        cout<<"\n\n\t\t ===== DANH SACH TIEU THUYET =====\n";
        for(int i=0;i<ds_tieuthuyet.size();i++)
        {
            cout<<"\n\n\t\t THONG TIN TIEU THUYET "<<i+1<<":";
            ds_tieuthuyet[i].output();
        }
        //tham khao
        cout<<"\n\n\t\t =====   DANH SACH SACH THAM KHAO =====\n";
         for(int i=0;i<ds_sachthamkhao.size();i++)
        {
            cout<<"\n\n\t\t THONG TIN SACH THAM KHAO "<<i+1<<":";
            ds_sachthamkhao[i].output();
        }
        //truyen tranh
        cout<<"\n\n\t\t =====  DANH SACH TRUYEN TRANH   =====\n";
         for(int i=0;i<ds_truyentranh.size();i++)
        {
            cout<<"\n\n\t\t THONG TIN TRUYEN TRANH "<<i+1<<":";
            ds_truyentranh[i].output();
        }
        //thieu nhi
        cout<<"\n\n\t\t =====  DANH SACH SACH THIEU NHI =====\n";
         for(int i=0;i<ds_thieunhi.size();i++)
        {
            cout<<"\n\n\t\t THONG TIN SACH THIEU NHI "<<i+1<<":";
            ds_thieunhi[i].output();
        }
    };
    double tinhtongtien()
	{
		double sum=0;
		for(int i=0;i<ds_sachgiaokhoa.size();i++)
		{
			sum+= ds_sachgiaokhoa[i].tinhtien();
		}
		for(int i=0;i<ds_tieuthuyet.size();i++)
		{
			sum+= ds_tieuthuyet[i].tinhtien();
		}
		for(int i=0;i<ds_sachthamkhao.size();i++)
		{
			sum+= ds_sachthamkhao[i].tinhtien();
		}
		for(int i=0;i<ds_truyentranh.size();i++)
		{
			sum+= ds_truyentranh[i].tinhtien();
		}
		for(int i=0;i<ds_thieunhi.size();i++)
		{
			sum+= ds_thieunhi[i].tinhtien();
		}
		return sum;
		
	};
};
int main()
{
    Thuvien *x=new Thuvien;
    x->input();
    x->output();
    cout<<"\n\n\t\t TONG TIEN ";cout<<x->tinhtongtien()<<" VND ";
	return cin.failure;
}
