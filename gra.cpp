#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("gra.txt");
    ofstream fout("wyniki.txt");
    int zyje=0;
    char T[12][20], R[12][20];
    fout<<"Pokolenie 1"<<endl;
    for(int a=0;a<12;a++)
    {
        for(int b=0;b<20;b++)
        {
            fin>>T[a][b];
            fout<<T[a][b];
        }
        fout<<endl;
    }
    fout<<endl;
    for(int i=0;i<99;i++)
        {
            fout<<"Pokolenie "<<i+2<<endl;
            for(int a=0;a<12;a++)
            {
                for(int b=0;b<20;b++)
                {
                    if(a==0 || b==0 || a==11 || b==19)
                    {
                        if(a==0 && b==0)
                        {
                            if(T[0][1]=='X')
                                zyje++;
                            if(T[1][0]=='X')
                                zyje++;
                            if(T[1][1]=='X')
                                zyje++;
                            if(T[0][19]=='X')
                                zyje++;
                            if(T[1][19]=='X')
                                zyje++;
                            if(T[11][19]=='X')
                                zyje++;
                            if(T[11][0]=='X')
                                zyje++;
                            if(T[11][1]=='X')
                                zyje++;
                            if((T[0][0]=='X'&&(zyje==2 || zyje==3)) || (T[0][0]=='.' && zyje==3))
                                R[0][0]='X';
                            else
                                R[0][0]='.';
                            zyje=0;
                        }
                        if(a==0 && b==19)
                        {
                            if(T[1][19]=='X')
                                zyje++;
                            if(T[1][18]=='X')
                                zyje++;
                            if(T[0][18]=='X')
                                zyje++;
                            if(T[11][18]=='X')
                                zyje++;
                            if(T[11][19]=='X')
                                zyje++;
                            if(T[11][0]=='X')
                                zyje++;
                            if(T[0][0]=='X')
                                zyje++;
                            if(T[1][0]=='X')
                                zyje++;
                            if((T[0][19]=='X'&&(zyje==2 || zyje==3)) || (T[0][19]=='.' && zyje==3))
                                R[0][19]='X';
                            else
                                R[0][19]='.';
                            zyje=0;
                        }
                        if(a==11 && b==0)
                        {
                            if(T[10][0]=='X')
                                zyje++;
                            if(T[10][1]=='X')
                                zyje++;
                            if(T[11][1]=='X')
                                zyje++;
                            if(T[0][1]=='X')
                                zyje++;
                            if(T[0][0]=='X')
                                zyje++;
                            if(T[0][19]=='X')
                                zyje++;
                            if(T[11][19]=='X')
                                zyje++;
                            if(T[10][19]=='X')
                                zyje++;

                            if((T[11][0]=='X'&&(zyje==2 || zyje==3)) || (T[11][0]=='.' && zyje==3))
                                R[11][0]='X';
                            else
                                R[11][0]='.';
                            zyje=0;
                        }
                        if(a==11 && b==19)
                        {
                            if(T[11][18]=='X')
                                zyje++;
                            if(T[10][18]=='X')
                                zyje++;
                            if(T[10][19]=='X')
                                zyje++;
                            if(T[10][0]=='X')
                                zyje++;
                            if(T[11][0]=='X')
                                zyje++;
                            if(T[0][0]=='X')
                                zyje++;
                            if(T[0][19]=='X')
                                zyje++;
                            if(T[0][18]=='X')
                                zyje++;
                            if((T[11][19]=='X'&&(zyje==2 || zyje==3)) || (T[11][19]=='.' && zyje==3))
                                R[11][19]='X';
                            else
                                R[11][19]='.';
                            zyje=0;
                        }
                    }
                    if(a==0 && b!=0 && b!=19)
                    {
                            if(T[a][b+1]=='X')
                                zyje++;
                            if(T[a+1][b+1]=='X')
                                zyje++;
                            if(T[a+1][b]=='X')
                                zyje++;
                            if(T[a+1][b-1]=='X')
                                zyje++;
                            if(T[a][b-1]=='X')
                                zyje++;
                            if(T[11][b-1]=='X')
                                zyje++;
                            if(T[11][b]=='X')
                                zyje++;
                            if(T[11][b+1]=='X')
                                zyje++;
                            if((T[a][b]=='X'&&(zyje==2 || zyje==3)) || (T[a][b]=='.' && zyje==3))
                                R[a][b]='X';
                            else
                                R[a][b]='.';
                            zyje=0;
                    }
                    if(a==11 && b!=0 && b!=19)
                    {
                            if(T[a][b+1]=='X')
                                zyje++;
                            if(T[0][b+1]=='X')
                                zyje++;
                            if(T[0][b]=='X')
                                zyje++;
                            if(T[0][b-1]=='X')
                                zyje++;
                            if(T[a][b-1]=='X')
                                zyje++;
                            if(T[a-1][b-1]=='X')
                                zyje++;
                            if(T[a-1][b]=='X')
                                zyje++;
                            if(T[a-1][b+1]=='X')
                                zyje++;
                            if((T[a][b]=='X'&&(zyje==2 || zyje==3)) || (T[a][b]=='.' && zyje==3))
                                R[a][b]='X';
                            else
                                R[a][b]='.';
                            zyje=0;
                    }
                    if(b==0 && a!=0 && a!=11)
                    {
                            if(T[a][b+1]=='X')
                                zyje++;
                            if(T[a+1][b+1]=='X')
                                zyje++;
                            if(T[a+1][b]=='X')
                                zyje++;
                            if(T[a+1][19]=='X')
                                zyje++;
                            if(T[a][19]=='X')
                                zyje++;
                            if(T[a-1][19]=='X')
                                zyje++;
                            if(T[a-1][b]=='X')
                                zyje++;
                            if(T[a-1][b+1]=='X')
                                zyje++;
                            if((T[a][b]=='X'&&(zyje==2 || zyje==3)) || (T[a][b]=='.' && zyje==3))
                                R[a][b]='X';
                            else
                                R[a][b]='.';
                            zyje=0;
                    }
                    if(b==19 && a!=0 && a!=11)
                    {
                            if(T[a][0]=='X')
                                zyje++;
                            if(T[a+1][0]=='X')
                                zyje++;
                            if(T[a+1][b]=='X')
                                zyje++;
                            if(T[a+1][b-1]=='X')
                                zyje++;
                            if(T[a][b-1]=='X')
                                zyje++;
                            if(T[a-1][b-1]=='X')
                                zyje++;
                            if(T[a-1][b]=='X')
                                zyje++;
                            if(T[a-1][0]=='X')
                                zyje++;
                            if((T[a][b]=='X'&&(zyje==2 || zyje==3)) || (T[a][b]=='.' && zyje==3))
                                R[a][b]='X';
                            else
                                R[a][b]='.';
                            zyje=0;
                    }

                    if(b!=19 && b!=0 && a!=0 && a!=11)
                    {
                            if(T[a][b+1]=='X')
                                zyje++;
                            if(T[a+1][b+1]=='X')
                                zyje++;
                            if(T[a+1][b]=='X')
                                zyje++;
                            if(T[a+1][b-1]=='X')
                                zyje++;
                            if(T[a][b-1]=='X')
                                zyje++;
                            if(T[a-1][b-1]=='X')
                                zyje++;
                            if(T[a-1][b]=='X')
                                zyje++;
                            if(T[a-1][b+1]=='X')
                                zyje++;
                            if((T[a][b]=='X'&&(zyje==2 || zyje==3)) || (T[a][b]=='.' && zyje==3))
                                R[a][b]='X';
                            else
                                R[a][b]='.';
                            zyje=0;
                    }
                }
            }
            for(int a=0;a<12;a++)
            {
                for(int b=0;b<20;b++)
                {
                    fout<<R[a][b];
                    T[a][b]=R[a][b];
                }

                fout<<endl;
            }
            fout<<endl;
        }
    fout.close();
}
