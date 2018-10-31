using System;
using System.Collections.Generic;
using System.Text;

namespace KeThua
{
    public class GiaSuc
    {
        //thuoc tinh
        protected int _Sua;
        protected int _Con;
        //property
        public int Sua
        {
            get
            {
                return this._Sua;
            }
            set
            {
                this._Sua = value;
            }
        }
        public int Con
        {
            get
            {
                return this._Con;
            }
            set
            {
                this._Con = value;
            }
        }
        //khoi tao.
        public GiaSuc()
        {
            this._Sua = 1;
            this._Con = 1;
        }
        public GiaSuc(int Sua, int Con)
        {
            this._Sua = Sua;
            this._Con = Con;
        }
        public GiaSuc(GiaSuc Gs)
        {
            this._Sua = Gs._Sua;
            this._Con = Gs._Con;
        }
        //so con
        public virtual void SinhCon()
        {
        }
        //luong sua
        public virtual void LuongSua()
        {
        }
    }
public class Bo:GiaSuc 
    {
        //thuoc tinh
        protected int[] _b;
        //property
        public int this[int i]
        {
            get
            {
                return this._b[i];
            }
            set
            {
                this._b[i] = value;
            }
        }
        public int N
        {
            get
            {
                return this._b.Length;
            }
        }
        //khoi tao.
        public Bo()
            : base()
        {
            this._b = new int[3] { 1,2,3};
        }
        public Bo(int sua, int con, int[] b)
            : base(sua, con)
        {
            this._b = new int[b.Length];
            for (int i = 0; i < b.Length; i++)
            {
                this._b[i] = b[i];
            }
        }
        public Bo(GiaSuc Gs, Bo b)
            : base(Gs)
        {
            this._b = new int[b.N];
            for (int i = 0; i < b.N; i++)
            {
                this._b[i] = b[i];
            }
        }
       //nhap
        public void Nhap()
        {
            Console.WriteLine("nhap vao so con bo: ");
            int n = int.Parse(Console.ReadLine());
            this._b = new int[n];
            for (int i = 0; i < this._b.Length; i++)
            {
                Console.Write("\n {0} con", i+1 );
                
            }
        }
       
        //so con
        public override void SinhCon()
        {
            base.SinhCon();
            Random r = new Random();
            int n = r.Next(0, 5);
            Console.Write("\n so lit sua la: "+n);
        }
        //luong sua
        public override void LuongSua()
        {
            base.LuongSua();
            Random r = new Random();
            int n = r.Next(0,20);
            Console.Write("\n so con bo la: "+n);
        }

    }
public class Cuu:GiaSuc
    {
        //thuoc tinh
        protected int[] _c;
        //property
        public int this[int i]
        {
            get
            {
                return this._c[i];
            }
            set
            {
                this._c[i] = value;
            }
        }
        public int N
        {
            get
            {
                return this._c.Length;
            }
        }
        //khoi tao.
        public Cuu()
            : base()
        {
            this._c = new int[3] { 1, 2, 3 };
        }
        public Cuu(int sua, int con, int[] c)
            : base(sua, con)
        {
            this._c = new int[c.Length];
            for (int i = 0; i < c.Length; i++)
            {
                this._c[i] = c[i];
            }
        }
        public Cuu(GiaSuc Gs, Cuu c)
            : base(Gs)
        {
            this._c = new int[c.N];
            for (int i = 0; i < c.N; i++)
            {
                this._c[i] = c[i];
            }
        }
        //nhap
        public void Nhap()
        {
            Console.WriteLine("\n\n nhap vao so con cuu: ");
            int n = int.Parse(Console.ReadLine());
            this._c = new int[n];
            for (int i = 0; i < this._c.Length; i++)
            {
                Console.Write("\n   {0} con", i + 1);
            }
        }
       
        //so con
        public override void SinhCon()
        {
            base.SinhCon();
            Random r = new Random();
            int n = r.Next(0, 5);
            Console.Write("\n so con cuu la: " + n);
        }
        //luong sua
        public override void LuongSua()
        {
            base.LuongSua();
            Random r = new Random();
            int n = r.Next(0, 15);
            Console.Write("\n so lit sua la: " + n);
        }
    }
 public class De:GiaSuc
    {
         //thuoc tinh
        protected int[] _d;
        //property
        public int this[int i]
        {
            get
            {
                return this._d[i];
            }
            set
            {
                this._d[i] = value;
            }
        }
        public int N
        {
            get
            {
                return this._d.Length;
            }
        }
        //khoi tao.
        public De()
            : base()
        {
            this._d = new int[3] { 1,2,3};
        }
        public De(int sua, int con, int[] d)
            : base(sua, con)
        {
            this._d = new int[d.Length];
            for (int i = 0; i < d.Length; i++)
            {
                this._d[i] = d[i];
            }
        }
        public De(GiaSuc Gs, De d)
            : base(Gs)
        {
            this._d = new int[d.N];
            for (int i = 0; i < d.N; i++)
            {
                this._d[i] = d[i];
            }
        }
       //nhap
        public void Nhap()
        {
            Console.WriteLine("\n\n nhap vao so con de: ");
            int n = int.Parse(Console.ReadLine());
            this._d = new int[n];
            for (int i = 0; i < this._d.Length; i++)
            {
                Console.Write("\n {0} con", i + 1);
            }
        }
        
        //so con
        public override void SinhCon()
        {
            base.SinhCon();
            Random r = new Random();
            int n = r.Next(0, 5);
            Console.Write("\n so con de la: "+n);
        }
        //luong sua
        public override void LuongSua()
        {
            base.LuongSua();
            Random r = new Random();
            int n = r.Next(0, 15);
            Console.Write("\n so lit sua la: "+n);
        }

    }
public static void Main(string[] args)
        {
            Bo b = new Bo();
            b.Nhap();
            
            b.SinhCon();
            b.LuongSua();
            De d = new De();
            d.Nhap();
            
            d.SinhCon();
            d.LuongSua();
            Cuu c = new Cuu();
            c.Nhap();
        
            c.LuongSua();
            c.SinhCon();
            Console.ReadLine();
        }
}


Read more: http://www.ddth.com/showthread.php/229526-b%C3%A0i-t%E1%BA%ADp-c%C4%83n-b%E1%BA%A3n-k%E1%BA%BF-th%E1%BB%ADa-mong-c%C3%A1c-b%E1%BA%A1n-gi%E1%BA%A3i-gi%C3%BAp#ixzz535PdWa4E
