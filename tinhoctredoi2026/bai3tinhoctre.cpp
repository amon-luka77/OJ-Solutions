#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
struct buoc{
    int x,y,a,b;
};
int n;
int mang[15][5];
int x4,y4;
int x8,y8;
int check[15][5];
vector<buoc> ans;
void dichuyen8(int posx,int posy)
{
   if(x8!=posx)
   {
     
   }
}
int main() {
cin>>n;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=4;j++)
    {
        cin>>mang[i][j];
        if(mang[i][j]==8){x8=i;y8=j;}
        if(mang[i][j]==4){x4=i;y4=j;}
    }
}
while(true)
{ int c=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(check[i][j]==true){c++}
        }
    }
  if(c==n*4){break;}
  for(int i=1;i<=n*4;i++)
  { if(i%4==0)continue;
    if(check[(i+3)/4][i%4+4*(i%4==0)]==true)continue;
    else{

        while(x4!=(i+3)/4&&y4!=i%4+4*(i%4==0))
        {
            if(x4>(i+3)){
                x4--;
                int temp=mang[x4][y4];
                mang[x4][y4]=4;
                mang[x4+1][y4]=temp;
                ans.push_back({x4+1,y4,x4,y4});

            }
            
            if(x4<(i+3)){
                x4++;
                int temp=mang[x4][y4];
                mang[x4][y4]=4;
                mang[x4-1][y4]=temp;
                ans.push_back({x4-1,y4,x4,y4});

            }
            if(y4>i%4+4*(i%4==0)){
                y4--;
                int temp=mang[x4][y4];
                mang[x4][y4]=4;
                mang[x4][y4+1]=temp;
                ans.push_back({x4,y4+1,x4,y4});
            }
        }       
        int posx,posy;
        for(int m=1;m<=n;m++)
        {
            for(int l=1;l<=4;l++ )
            {
                if(mang[m][l]==i){posx=m;posy=l;}
            }
        }
        while(posx!=(i+3)/4&&posy!=i%4+4*(i%4==0))
        {
            while(posy!=i%4+4*(i%4==0))
            {  
              if(posy>i%4+4*(i%4==0))dichuyen8(int posx,int posy-1);
              else dichuyen8(int posx,int posy+1);
            }
        }
    }
  }
}
}