//
//  main.cpp
//  cs341_a3q1
//
//  Created by Devin Qi on 2016-02-28.
//  Copyright © 2016 Devin Qi. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;



class Cell{
public:
    int num;                    //this cell's order
    int laderto;                //if it has a lader, where it goes to
    int snaketo;                //if it has a snake, where it goes to
    int next;
    int visited;
    int dis;
    Cell(int n){
        
        num = n;
        laderto = -1;
        snaketo = -1;
        next = n+1;
        dis = 0;
    }
    Cell(){}
};
class Map{
public:
    Cell * cellarray;
    int num;
    Map(int n ){
        cellarray = new Cell[n*n];
        for(int i = 0;i < n*n;i++){
            cellarray[i] = Cell(0);
        }
        num = n*n;
    }
    ~Map(){
        delete[] cellarray;
    }
};

int do_nomal(Map & M,int num,int i){
    int firstl = 10000000;
    Cell * c = M.cellarray;
    int cc = 0;
    while (i < num) {
        //cout << i << "    " << c[i].dis<<"     "<<firstl<<endl;
        if (c[i].snaketo != -1){
            int j = i;
            int six_l= 1;
            int jj = c[j].snaketo;
            int minmums = 1000000;
            while(jj < num ){
                //cout << minmums<<endl;;
                //cout <<c[jj].laderto<< "   "<<c[jj+1].laderto  <<"    " <<six_l <<endl;
                if((c[jj].laderto != -1)&&(c[jj+1].laderto != -1)){
                    
                    minmums =min(min(minmums,c[jj].laderto),c[jj+1].laderto);
                    six_l++;
                }else{
                    minmums=1000000;
                    six_l = 1;
                }
                if (six_l >= 6){
                    c[minmums].dis = c[j].dis;
                    return do_nomal(M,num, minmums);
                }
                jj++;
            }

            int d = 0;
            int dd = 0;
            int ccc= 1;
            int wo = 1;
            while(j < num){
                //cout << j <<"  ccc:" <<ccc<< "    c[j].dis:"<<c[j].dis<<endl;
                if ((c[j].snaketo != -1)&&(c[j+1].snaketo !=-1)){
                    ccc++;
                    wo = 1;
                }
                if (ccc >= 6){
                    dd = 1;
                }
                if ((wo==0)&&(c[j].dis!= 0)){
                    d = 1;
                    break;
                }
                ++j;
                wo =0;
            }
            if((d == 0) &&(dd == 1)){
                cout << "impossible"<<endl;
                return 1;
            }
            cout << "infinity"<<endl;
            return 1;
        }
        if(c[i].dis == -1){
            firstl = min(c[i].laderto,firstl);
            cc++;
            if(cc == 6){
                i = firstl;
                firstl = 10000000;
            }else{
                i++;
            }
            continue;
        }
        if((i+1 < num)&&(c[i+1].dis <= c[i].dis)){
            if(c[i+1].laderto != -1){
                c[c[i+1].laderto].dis =c[i].dis +1;
                c[i+1].dis = -1;
            }else{
                c[i+1].dis = c[i].dis+1;
            }
        }
        if((i+2 < num)&&(c[i+2].dis <= c[i].dis)){
            if(c[i+2].laderto != -1){
                c[c[i+2].laderto].dis =c[i].dis +1;
                c[i+2].dis = -1;
            }else{
                c[i+2].dis = c[i].dis+1;
            }
        }
        if((i+3 < num)&&(c[i+3].dis <= c[i].dis)){
            if(c[i+3].laderto != -1){
                c[c[i+3].laderto].dis =c[i].dis +1;
                c[i+3].dis = -1;
            }else{
                c[i+3].dis = c[i].dis+1;
            }
        }
        if((i+4 < num)&&(c[i+4].dis <= c[i].dis)){
            if(c[i+4].laderto != -1){
                c[c[i+4].laderto].dis =c[i].dis +1;
                c[i+4].dis = -1;
            }else{
                c[i+4].dis = c[i].dis+1;
            }
        }
        if((i+5 < num)&&(c[i+5].dis <= c[i].dis)){
            if(c[i+5].laderto != -1){
                c[c[i+5].laderto].dis =c[i].dis +1;
                c[i+5].dis = -1;
            }else{
                c[i+5].dis = c[i].dis+1;
            }
        }
        if((i+6 < num)&&(c[i+6].dis <= c[i].dis)){
            if(c[i+6].laderto != -1){
                c[c[i+6].laderto].dis =c[i].dis +1;
                c[i+6].dis = -1;
            }else{
                c[i+6].dis = c[i].dis+1;
            }
        }
        i++;
    }
    return 0;
}



int main(){
    int n=0;
    int num_lader=0;
    int num_snake=0;
    cin >> n >> num_lader>> num_snake;
    int num_cell = n*n;
    Map M(n);
    for (int i = 0;  i < num_cell;i++){
        Cell c(i+1);
        M.cellarray[i] = c;
    }
    for(int i = 0; i < num_lader;i++){
        int start;
        int end;
        cin >> start>>end;
        M.cellarray[start].laderto = end;
    }
    for (int i = 0;i< num_snake;++i){
        int start;
        int end;
        cin >> start>>end;
        M.cellarray[start].snaketo = end;
    }
    M.cellarray[0].dis = 0;
    int tt = do_nomal(M,num_cell,0);
    if(tt ==0){
    cout << M.cellarray[n*n-1].dis<<endl;
    }
    return 0;
}
