#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<vector>
#include<thread>
#include<unordered_map>
#include<chrono>
#include<math.h>
#include<stdlib.h>

using namespace std;

class RSA{
public:
    int p;
    int q;
    long int n, t, flag, e[100], d[100], temp[100], j, m[100], i;

    vector<int> encryption(string x)
    {
        vector<int> en;
        p = 5;
        q = 7;
        if (are_distinct(p, q) == true)
        {
            n = p * q;
            t = (p - 1) * (q - 1);
            for (i = 0; x[i] != '\0'; i++)
                m[i] = x[i];
            ce();
            long int pt, ct, key = e[0], k, len;
            i = 0;
            len = x.size();
            while (i != len)
            {
                pt = m[i];
                pt = pt - 96;
                k = 1;
                for (j = 0; j < key; j++)
                {
                    k = k * pt;
                    k = k % n;
                }
                temp[i] = k;
                ct = k + 96;
                en.push_back(ct);
                i++;
            }
            en[i] = -1;
            return en;
        }
    }

    void ce()
    {
        int k;
        k = 0;
        for (i = 2; i < t; i++)
        {
            if (t % i == 0)
                continue;
            flag = check_prime(i);
            if (flag == 1 && i != p && i != q)
            {
                e[k] = i;
                flag = cd(e[k]);
                if (flag > 0)
                {
                    d[k] = flag;
                    k++;
                }
                if (k == 99)
                    break;
            }
        }
    }

    long int cd(long int x)
    {
        long int k = 1;
        while (1)
        {
            k = k + t;
            if (k % x == 0)
                return (k / x);
        }
    }

    int check_prime(long int pr)
    {
        int i;
        j = sqrt(pr);
        for (i = 2; i <= j; i++)
        {
            if (pr % i == 0)
                return 0;
        }
        return 1;
    }

    int generate_prime()
    {
        while (true)
        {
            int r = rand();
            if (check_prime(r) == 1)
            {
                return r;
            }
        }
    }

    bool are_distinct(int x, int y)
    {
        if (x == y)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

class Try_to_login : public RSA
{
private:
    string Attempted_username;
    string Attempted_pass;

public:
    class struct_data
    {
    public:
        string Username;
        vector<int> parola;
    };

    void login()
    {
        cout << "You may enter passwords and usernames that don't have the space character in them !" << endl;
        cout << "Type your username:" << endl;
        cin >> Attempted_username;
        cout << "Type your password:" << endl;
        cin >> Attempted_pass;

        vector<int> Encriptie = encryption(Attempted_pass);
        vector<struct_data> Vector = get_data("Operatori.txt");
        bool flag = false;

        for (auto it = Vector.begin(); it != Vector.end(); it++) 
        {
            if (Attempted_username == it->Username)
            {
                ofstream g("criptare_1.txt");
                ofstream f("criptare_2.txt");

                for (auto i = (it->parola).begin(); i != (it->parola).end(); i++)
                    g << (*i);
                g << "\0";
                for (auto j = Encriptie.begin(); j != Encriptie.end(); j ++)
                    f << (*j);
                f << "\0";

                f.close();
                g.close();
                
                ifstream pin("criptare_1.txt");
                ifstream qin("criptare_2.txt");

                string sir1, sir2;

                while ((!pin.eof()) && (!qin.eof()))
                {
                    getline(pin, sir1);
                    getline(qin, sir2);
                }
                
                if(sir1 == sir2) 
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag == true)
        {
            cout << "Successfully logged in !";
            return;
        }

        if (flag == false)
        {
            bool flag1 = false;
            for (auto it = Vector.begin(); it != Vector.end(); it++)
            {
                if (Attempted_username == it->Username)
                {
                    flag1 = true;
                    throw "Login failed, wrong password !";
                    break;
                }
            }
            if (flag1 == false)
            {
                throw "Login failed, wrong username !";
            }
        }
    }
    
    vector<struct_data> get_data(const char *input_file)
    {
        fstream file;
        file.open(input_file);

        vector<struct_data> data;
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                struct_data s1;
                int c = 0;
                for (auto i : line)
                {
                    c++;
                    if (i == ',')
                        break;
                    
                    s1.Username.push_back(i);
                }
                for (auto j = c; j < line.length(); j++)
                {
                    s1.parola.push_back(line[j] - '0'); 
                }
                data.push_back(s1);
            }
        }
        return data;
    }
};

int glob = 0; 
int global = 10;

class d_booking 
{
protected:
    int pnr;
    char f_d[10], toja[7], tojd[7]; 
    long int doj;
    int choice, src, dest;

public: 
    void d_pnr()
    {
        glob++; 
        pnr = glob;
    }
    int j_detail()
    {
        cout << "\nEnter DateOfJourney(DDMMYY)." << "Please enter a valid date." << endl;
        cin >> doj;
        cout << "\1.Brisbane(1) \t\2.Sydney(2) \t\3.Melbourne(3) \t\4.Canberra(4)" << endl << endl;
        cout << "\tEnter Source" << endl;
        cin >> src;
        cout << "\tEnter destination" << endl;
        cin >> dest;
        if ((src == 1 && dest == 2) || (src == 2 && dest == 1)) 
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\t\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\t\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t17:05\t\t\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\t\n";
        }

        else if ((src == 1 && dest == 3) || (src == 3 && dest == 1)) 
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\t\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\t\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t17:05\t\t\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\t\n";
        }

        else if ((src == 1 && dest == 4) || (src == 4 && dest == 1)) 
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\t\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\t\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t17:05\t\t\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\t\n";
        }

        else if ((src == 2 && dest == 3) || (src == 3 && dest == 2)) 
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\t\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\t\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t17:05\t\t\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\t\n";
        }

        else if ((src == 2 && dest == 4) || (src == 4 && dest == 2)) 
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\t\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\t\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t17:05\t\t\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\t\n";
        }
        else if ((src == 3 && dest == 4) || (src == 4 && dest == 3)) 
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\t\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\t\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t17:05\t\t\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\t\n";
        }
        else if (src == dest) 
        {
            cout << "\nSource and destination can't be same.\nTry again\n\n\n" << endl;
            return j_detail();
        }
        else
        {
            cout << "\nWrong input entered\nTry again\n\n\n" << endl;
            return j_detail();
        }
    }

    int select_flight() 
    {
        cout << "\nEnter your choice" << endl;
        cin >> choice;
        switch (choice) 
        {
        case 1: 
            cout << "\nFlight selected:" << endl;
            cout << "Qantas" << endl;
            strcpy(f_d, "Qantas");
            strcpy(tojd, "8:00");  
            strcpy(toja, "11:05"); 
            break;
        case 2: 
            cout << "\nFlight selected:" << endl;
            cout << "Fly Dubai" << endl;
            strcpy(f_d, "Fly Dubai");
            strcpy(tojd, "14:00"); 
            strcpy(toja, "17:05"); 
            break;
        case 3: 
            cout << "\nFlight selected:" << endl;
            cout << "Go Air" << endl;
            strcpy(f_d, "Go Air");
            strcpy(tojd, "19:00"); 
            strcpy(toja, "22:05"); 
            break;
        default: 
            cout << "Wrong input entered.\nTry again" << endl;
            return select_flight();
        }
    }
};

class i_booking 
{
protected: 
    int pnri;
    char f_i[10], tojai[7], tojdi[7];
    long int doji;
    int srci, desti, choicei;

public: 
    void i_pnr()
    {
        global++; 
        pnri = global;
    }
    
    int j_detaili() 
    {
        cout << "Enter DateOfJourney(DDMMYY)." << "Please enter a valid date." << endl;
        ;
        cin >> doji;
        cout << "\1.London(1) \2.Dubai(2) \3.Abu Dhabi(3) \4.Singapore(4) \5.NewYork(5) " << endl << endl;
        cout << "\tEnter Source" << endl;
        cin >> srci;
        cout << "\nEnter destination";
        cin >> desti;
        cout << "\t \t \tFlights Found" << endl << endl;

        if ((srci == 1 && desti == 3) || (srci == 3 && desti == 1)) 
        {
            cout << "Airline:\tDeparture:\tArrival:\t\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\t\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05\t\t\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\t\n";
        }

        else if ((srci == 1 && desti == 4) || (srci == 4 && desti == 1)) 
        {
            cout << "Airline:\tDeparture:\tArrival:\t\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\t\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05\t\t\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\t\n";
        }

        else if ((srci == 1 && desti == 5) || (srci == 5 || desti == 1)) 
        {
            cout << "Airline:\tDeparture:\tArrival:\t\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\t\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05\t\t\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\t\n";
        }

        else if ((srci == 2 && desti == 3) || (srci == 3 && desti == 2)) 
        {
            cout << "Airline:\tDeparture:\tArrival:\t\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\t\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05\t\t\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\t\n";
        }

        else if ((srci == 2 && desti == 4) || (srci == 4 && desti == 2)) 
        {
            cout << "Airline:\tDeparture:\tArrival:\t\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\t\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05\t\t\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\t\n";
        }

        else if (srci == 2 && desti == 5 || (srci == 5 && desti == 2)) 
        {
            cout << "Airline:\tDeparture:\tArrival:\t\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\t\n";
            cout << "\2.Fly Dubai(2)\t14:00\t\t18:05\t\t\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\t\n";
        }
        else if (srci == desti) 
        {
            cout << "wrong input entered.\nTry again\n\n\n" << endl;
            return j_detaili();
        }
        else 
        {
            cout << "Wrong input entered.\nTry again\n\n\n";
            return j_detaili();
        }
    }

    int select_flighti() 
    {
        cout << "\nEnter your choice" << endl;
        cin >> choicei;
        switch (choicei) 
        {
        case 1: 
            cout << "\nFlight selected:" << endl;
            cout << "Vistara" << endl;
            strcpy(f_i, "Vistara");
            strcpy(tojdi, "10:00"); 
            strcpy(tojai, "14:05"); 
            break;
        case 2: 
            cout << "\nFlight selected:" << endl;
            cout << "Fly Dubai" << endl;
            strcpy(f_i, "Fly Dubai");
            strcpy(tojdi, "14:00"); 
            strcpy(tojai, "18:05"); 
            break;
        case 3: 
            cout << "\nFlight selected:" << endl;
            cout << "Emirates" << endl;
            strcpy(f_i, "Emirates"); 
            strcpy(tojdi, "18:00"); 
            strcpy(tojai, "22:05"); 
            break;
        default: 
            cout << "Wrong input entered" << endl;
            return select_flighti();
        }
    }
};

class passenger : public d_booking, public i_booking 
{
protected: 
    char f_name[20], l_name[20];

public:                  
    void p_detail(int x) 
    {
        if (x == 1) 
        {
            j_detail();      
            select_flight(); 
        }
        else
        {
            j_detaili();      
            select_flighti(); 
        }
    }

    int getpnr() 
    {
        return pnr;
    }

    int getpnri() 
    {
        return pnri;
    }

    void disp() 
    {
        cout << "Flight:" << f_d << endl;
        cout << "Departure Time:" << tojd << endl;
        cout << "Arrival Time:" << toja;
    }

    void dispi() 
    {
        cout << "Flight:" << f_i << endl;
        cout << "Departure Time:" << tojdi << endl;
        cout << "Arrival Time:" << tojai;
    }
};

int main()
{
    char type, type2;

    cout << "Are you an operator ? (Y/y) or (N/n)\n";
    cin >> type;

    if (type == 'Y' || type == 'y')
    {
        Try_to_login obj1;
        ofstream file;
        file.open("Operatori.txt");

        vector<int> Vector1 = obj1.encryption("Parola1");
        vector<int> Vector2 = obj1.encryption("Parola2");

        if (file.is_open())
        {
            file << "Operator1" << ",";
            for (auto it = Vector1.begin(); it != Vector1.end(); it++)
            {
                file << (*it);
            }
            file << "\n" << "Operator2" << ",";
            for (auto it = Vector2.begin(); it != Vector2.end(); it++)
            {
                file << (*it);
            }
        }
        file.close();
        try
        {
            obj1.login();
        }
        catch (const char *msg)
        {
            cerr << msg << endl;
        }
    }
    else if (type == 'N' || type == 'n')
    {
        cout << "Are you an user ? (Y/y) or (N/n)";
        cin >> type;
        if (type == 'Y' || type == 'y')
        {
            cout << "Do you want to register as an new user ? (Y/y) or (N/n)";
            cin >> type2;

            if (type2 == 'Y' || type2 == 'y')
            {
                Try_to_login obj3;
                ofstream file;
                file.open("Users_dates.txt", std::fstream::in | std::fstream::out | std::fstream::app);

                string parola_confirm, parola;
                bool address_sign = false;
                char new_user_email[200]; 
                
                while (1)
                {
                    cout << "Type your email for this new user account : \n";
                    cin >> new_user_email;

                    cout << "Type your password for this new user account : \n";
                    cin >> parola;

                    cout << "Type your password again : \n";
                    cin >> parola_confirm;

                    for (int i = 0; i < strlen(new_user_email) && address_sign == false; i++)
                    {
                       if(new_user_email[i] == '@') address_sign = true;   
                    }
                    if(address_sign == true)
                    {
                        if (parola_confirm == parola)
                        {
                            cout << "The passwords are identical !\n";
                            break;
                        }
                        else
                        {
                            cout << "The passwords are not identical !\nYou have to type your email and password again !\n";
                            continue;
                        }
                    }
                    else
                    {
                        cout << "The email address is not correct !\n";
                        continue;
                    }
                    
                }
                vector<int> Vector_p = obj3.encryption(parola);

                if (file.is_open())
                {
                    file << new_user_email << ",";
                    for (auto it = Vector_p.begin(); it != Vector_p.end(); it++)
                    {
                        file << (*it);
                    }
                    file << "\n";
                }
                
                cout << "Congrats ! You're registered as an new user now !\n";
                cout << "Would you like to continue booking a flight ? (Y/y) or (N/n)\n";
                cin >> type2;

                if (type2 == 'Y' || type2 == 'y')
                {
                    passenger p1;
                    cout << "\n\n\1.Domestic Fights(1) \n\2.International Flights(2)" << endl;
                    cout << "\nPlease enter your option" << endl;

                    int ch1;
                    cin >> ch1;
                    switch (ch1)
                    {
                    case 1:
                        p1.p_detail(1);
                        p1.d_pnr();
                        p1.disp();
                        break;
                    case 2:            
                        p1.p_detail(2); 
                        p1.i_pnr();
                        p1.dispi();
                        break;
                    default: 
                        cout << "Wrong input entered\nTry again\n\n\n" << endl;
                        return main();
                    }
                }
                else if (type2 == 'N' || type2 == 'n')
                {
                    cout << "Thank you for the registration !\n";
                    return 0;
                }
            }
            else if (type2 == 'N' || type2 == 'n')
            {
                cout << "That's mean you already have an account as an user. Please log in !\n";

                ifstream in;
                in.open("Users_dates.txt");

                char email[300], email_in[300], parola[300];
                string parola_in;
                bool flag = false;

                cout << "Type your email : \n";
                cin >> email_in;

                cout << "Type your password : \n";
                cin >>parola_in;

                while (!in.eof() && flag == false)
                {
                    in >> email;

                    if (strstr(email, email_in))
                        flag = true;
                }

                if(flag == true)
                {
                    strcpy(parola, strchr(email, ',') + 1);

                    Try_to_login obj4;

                    vector<int> Vector_p = obj4.encryption(parola_in);

                    ofstream g("criptare_1.txt");
                    ofstream f("criptare_2.txt");

                    for(int i = 0; i < strlen(parola); i ++)
                        g << parola[i];
                    
                    for (auto j = Vector_p.begin(); j != Vector_p.end(); j++)
                        f << (*j);
                    f << "\0";

                    f.close();
                    g.close();

                    ifstream pin("criptare_1.txt");
                    ifstream qin("criptare_2.txt");

                    string sir1, sir2;
                    bool flag2 = false;

                    while ((!pin.eof()) && (!qin.eof()))
                    {
                        getline(pin, sir1);
                        getline(qin, sir2);
                    }

                    if (sir1 == sir2)
                    {
                        flag2 = true;
                    }

                    if(flag2 == true)
                        {
                            cout << "Successfully login as an user !\n";
                            
                            passenger p1;
                            cout << "\n\n\1.Domestic Fights(1) \n\2.International Flights(2)" << endl;
                            cout << "\nPlease enter your option" << endl;

                            int ch1;
                            cin >> ch1;
                            switch (ch1)
                            {
                            case 1:
                                p1.p_detail(1);
                                p1.d_pnr();
                                p1.disp();
                                break;
                            case 2:
                                p1.p_detail(2);
                                p1.i_pnr();
                                p1.dispi();
                                break;
                            default:
                                cout << "Wrong input entered\nTry again\n\n\n"
                                     << endl;
                                return main();
                            }
                        }
                    else
                        cout << "The password is incorrect !\n";
                }
                else
                {
                    cout << "The account associated with this email does not exist !\n";
                    return 0;  
                }
                
            }
        }
        else return 0;
    }
    return 0;
}