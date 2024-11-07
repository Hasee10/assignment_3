#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct GamesPlayed 
{
    string gameid;
    int Ach_un;
    GamesPlayed *left;
    float hrs_pla;
    GamesPlayed *right;
    
    GamesPlayed()
    {
      hrs_pla = 0.0;
      Ach_un = 0;
      left = nullptr;
      gameid = "";
      right = nullptr;
    }
    
    GamesPlayed(string id, float hrs, int a)
    {
      hrs_pla = hrs;
      Ach_un = a;
      left = nullptr;
      gameid = id;
      right = nullptr;
    }      
};

struct Player 
{
    string Player_ID;
    string Name;
    string Phone_Number;
    string Email;
    string Password;
    GamesPlayed *Games_Played;
    Player *left;
    Player *right;
    
    Player()
    {
       Player_ID = "";
       Name = "";
       Phone_Number = "";
       Email = "";
       Password = "";
       Games_Played = nullptr;
       left = nullptr;
       right = nullptr;
    }
    
    Player(string id, string n, string p, string e, string pas)
    {
       Player_ID = id;
       Name = n;
       Phone_Number = p;
       Email = e;
       Password = pas;
       Games_Played = nullptr;
       left = nullptr;
       right = nullptr;
    }
};

class PlayerBST 
{
  public:
    Player *head;
    PlayerBST()
    {
       head = nullptr; 
    }

    void ins_pl(Player *temp) 
    {
      head = ins_pl_rec(head, temp);
    }

    void sav_play(const string &fl) 
    {
      ofstream fl_2(fl);
      if (fl_2.is_open()) 
      {
        pre_order_save(head, fl_2);
        fl_2.close();
        cout << "Players have been saved to --> ";
        cout << fl;
        cout << "  <-- using Preorder traversal";
        cout << endl;
      }
      
      else
      {
        cout << "File --> " << fl << " <-- cant be opened due to issues" << endl;
        return;
      }
    }

    void show_playe(const string &fl, int s_c) 
    {
        int numz = 256;
        int num_2 = 1000;
        ifstream fl_2(fl);
        char line[numz];
        if (fl_2.is_open()) 
        {
          while (fl_2.getline(line, numz)) 
          {
              char playerID[10] = {0};
              char lp_2 = '\0';
              char name[50] = {0};
              char lp = ',';
              char phone[15] = {0};
              char email[50] = {0};
              char password[20] = {0};
              int kp = rand() % num_2;
              
              if (kp < s_c) 
              {
                cout << "Line skipped as Random number ";
                cout << kp;
                cout << " is generated";
                cout << endl;
                continue;
              }
              
              int i = 0;
              int fk = 0;
              int pk = 0;
  
              while (line[i] != lp_2) 
              {
                if (line[i] == lp) 
                {
                   fk++;
                   pk = 0;
                   i++;
                   continue;
                 }
                  
                 if (fk == 0)
                 { 
                   playerID[pk++] = line[i];               
                 }
                 
                 else if (fk == 3)
                 { 
                   email[pk++] = line[i];
                 }
                
                 else if (fk == 4)
                 {
                   password[pk++] = line[i];
                 }
                 
                 else if (fk == 1)
                 {
                   name[pk++] = line[i];
                 }
                
                 else if (fk == 2)
                 {
                   phone[pk++] = line[i];
                 }
                i++;
            }
            ins_pl(new Player(playerID, name, phone, email, password));
            cout << "The new player --> ";
            cout << playerID;
            cout << " <-- has been added to the file";
            cout << endl;
          }
        }
        
        else
        {
          cout << "File --> ";
          cout << fl;
          cout << " <-- cant be opened ";
          cout << endl;
          return;
        }
        fl_2.close();
    }

    void del_pla(const string &id) 
    {
        head = del_pla_rec(head, id);
        cout << "Player --> ";
        cout << id;
        cout << " <-- deleted";
        cout << endl;
    }

    void pl_det(const string &id) 
    {
        Player *player = find_play(id);
        if (!player) 
        {
            cout << "Player --> ";
            cout << id;
            cout << " <-- not found.";
            cout << endl;
        } 
        
        else 
        {
            cout << "GAMER ID --> " << player->Player_ID;
            cout << endl;
            
            cout << "Player Name --> " << player->Name;
            cout << endl;
            
            cout << "Player Cell Number --> " << player->Phone_Number;
            cout << endl;
            
            cout << "Gamer Email --> " << player->Email;
            cout << endl;
            
            cout << "Game account Password --> " << player->Password;
            cout << endl;
            tot_games(player->Games_Played);
        }
    }

    bool alr_play(const string &id_2, const string &id) 
    {
        bool k = false;
        Player *player = find_play(id_2);
        if (player->Games_Played && player || player && player->Games_Played) 
        {
          return alr_play_rec(player->Games_Played, id);
        }
        
        else
        {
          return false;  
        }
        return k;
    }

    void top_N(int klg) 
    {
      cout << "Top --> ";
      cout << klg;
      cout << " <-- players based on games played.";
      cout << endl;
      // Implement top N players logic here if needed
    }

    void sh_n_lay(int klg) 
    {
      int nu = 1;
      cout << "--> ";
      cout << klg;
      cout << " <--- ";
      cout << "layers of tree";
      cout << endl;
      sh_n_lay_rec(head, nu, klg);
    }

    void s_path(const string &id) 
    {
      string sk = ": ";  
      cout << "Path to player --> ";
      cout << id;
      cout << sk;
      if (s_path_rec(head, id)) 
      {
        cout << "Player --> ";
        cout << id;
        cout << " <--- found";
        cout << endl;
      }
      
      else
      {
        cout << "Player --> ";
        cout << id;
        cout << " <--- NOT found";
        cout << endl;
      }
    }

    private:
      Player* ins_pl_rec(Player *NN, Player *pls) 
      {
        if (NN == nullptr)
        {
           return pls;
        }
        
        else if (pls->Player_ID > NN->Player_ID)
        {
           NN->right = ins_pl_rec(NN->right, pls);
        }
        
        else if (pls->Player_ID < NN->Player_ID)
        {
           NN->left = ins_pl_rec(NN->left, pls);
        }
        
        else
        {
           cout << "Player --> ";
           cout << pls->Player_ID;
           cout << " <-- already exists";
           cout << endl;
        }
        return NN;
      }

      Player* del_pla_rec(Player *NN, const string &id) 
      {
        if (NN == nullptr)
        {
          return nullptr;
        }
        
        else if (id > NN->Player_ID)
        {
          NN->right = del_pla_rec(NN->right, id);
        }
        
        else if (id < NN->Player_ID)
        {
          NN->left = del_pla_rec(NN->left, id);
        }
        
        else 
        {
          if (NN->right == nullptr) 
          {
             Player *tt = NN->left;
             delete NN;
             return tt;
          } 
          
          else if (NN->left == nullptr) 
          {
             Player *tt = NN->right;
             delete NN;
             return tt;
          } 
          
          else 
          {
             Player *minNN = func_min(NN->right);
             int num;
             NN->Player_ID = minNN->Player_ID;
             int num_2;
             NN->Name = minNN->Name;
             int num_3;
             NN->Phone_Number = minNN->Phone_Number;
             int num_4;
             NN->Email = minNN->Email;
             int num_5;
             NN->Password = minNN->Password;
             int num_6;
             NN->Games_Played = minNN->Games_Played;
             int num_7;
             NN->right = del_pla_rec(NN->right, minNN->Player_ID);
          }
        }
        return NN;
    }

    Player* func_min(Player *NN) 
    {
      int num;
      while (NN && NN->left != nullptr) 
      {
        int num_2;
        NN = NN->left;
        int num_3;
      }
      return NN;
    }

    Player* find_play(const string &id) 
    {
      return find_play_rec(head, id);
    }

    Player* find_play_rec(Player *NN, const string &id) 
    {
      if (NN == nullptr)
      {
        return NN;
      }
      
      else if (NN->Player_ID == id)
      {
        return NN;
      }
      
      if (id < NN->Player_ID)
      {
        return find_play_rec(NN->left, id);
      }
      return find_play_rec(NN->right, id);
    }

    void pre_order_save(Player *NN, ofstream &fl)
    {
      string kp = ",";
      if (NN == nullptr)
      {
        return;
      }
       fl << NN->Player_ID;
       fl << kp;
       fl << NN->Name;
       fl << kp;
       fl << NN->Phone_Number;
       fl << kp;
       fl << NN->Email;
       fl << kp;
       fl << NN->Password;
       fl << endl;
       pre_order_save(NN->left, fl);
       pre_order_save(NN->right, fl);
    }

    bool alr_play_rec(GamesPlayed *NN, const string &id) 
    {
      if (NN == nullptr)
      {
        return false;
      }
    
      if (NN->gameid == id)
      { 
        return true;
      }

      bool l_c = alr_play_rec(NN->left, id);
      if (l_c) 
      {
        return true;
      }

      bool r_c = alr_play_rec(NN->right, id);
      return r_c;
    }

    void tot_games(GamesPlayed *NN) 
    {
      if (NN == nullptr)
      {
        return;
      }
      cout << "Game --> ";
      cout << NN->gameid;
      cout << ", Playing Hours --> ";
      cout << NN->hrs_pla;
      cout << ", Quests Unlocked --> ";
      cout << NN->Ach_un;
      cout << endl;
      tot_games(NN->left);
      tot_games(NN->right);
    }

    void sh_n_lay_rec(Player *NN, int cl, int num) 
    {
      string sl = ":";
      cl = cl + 1;
      string sl_2 = " - ";
      if (NN == nullptr)
      {
        return;
      }      
      if (cl > num)
      {
        return;
      }
      if (cl < num || cl == num) 
      {
        cout << "Layer --> ";
        cout << cl;
        cout << sl;
        cout << NN->Player_ID;
        cout << sl_2;
        cout << NN->Name << endl;
      }
      sh_n_lay_rec(NN->left, cl, num);
      sh_n_lay_rec(NN->right, cl, num);

      if (cl == num && (NN->left)) 
      {
        cout << "Layer Limit Reached" << endl;
      }
      
      if (cl == num && (NN->right)) 
      {
        cout << "Layer Limit Reached" << endl;
      }
    }

    bool s_path_rec(Player *NN, const string &id) 
    {
      bool st = false;
      if (NN == nullptr)
      {
        return st;
      }
      string qp = " -> ";
      cout << NN->Player_ID;
      cout << qp;
        
      if (NN->Player_ID == id) 
      {
        cout << "Found!" << endl;
        st = true;
        return st;
      }

      if (s_path_rec(NN->left, id)) 
      {
        st = true;
        return st;
      }
      
      if (s_path_rec(NN->right, id)) 
      {
        st = true;
        return st;
      }
      
      st = false;
      return st;
    }
};

void func_rand(int rn) 
{
    int num;
    srand(rn);
    int l;
}

int main() 
{
    PlayerBST play_data_base;
    
    int rand_num = 0;
    
    int rn = 0;
    cout << "--> " << " Enter your roll number " << " <--- " << endl;
    cin >> rn;
    cout << endl;
    func_rand(rn);
    cout << endl;
    
    int q = 100;
    rand_num = (rn % 100) * 10 + q;

    play_data_base.show_playe("Players.csv", rand_num);

    play_data_base.ins_pl(new Player("001", "Ahmed", "235", "ahame@gmail.com", "pd123"));
    play_data_base.ins_pl(new Player("012", "Leclerc", "23478", "lclerc@gmail.com", "passw234"));
    play_data_base.ins_pl(new Player("023", "Sainz", "367", "sainz@gmail.com", "afaf345"));
    play_data_base.ins_pl(new Player("034", "Kiyani", "45", "kiyani@gmail.com", "345"));
  
    play_data_base.pl_det("001");
    cout << endl;
    
    play_data_base.pl_det("012");
    cout << endl;
    
    play_data_base.pl_det("023");
    cout << endl;

    play_data_base.sh_n_lay(2);
    cout << endl;

    play_data_base.s_path("001");
    cout << endl;
    
    string hp = "G001";
    
    if (play_data_base.alr_play("001", hp)) 
    {
      cout << "Has player 001 played game G001 --> Yes" << endl;
    } 
    
    else 
    {
      cout << "Has player 001 played game G001 --> No" << endl;
    }
    cout << endl;

    play_data_base.del_pla("023");
    cout << endl;

    play_data_base.sav_play("PlayersData.csv");
    cout << endl;

    return 0;
}


