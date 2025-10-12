typedef int Key;
typedef struce {
    Key key; char information[10];
} Data;

#define less(A,B) (A<B)
#define exch(A,B) {data t=A; A=B; B=t;}
#define compexch(A,B) if (less(B,A)) exch(A,B)
#difine eq(A,B) (A==B)

Data Nulldata;

Key DATArand(void);
int DATAscan(Key *);
void DATAshow(Data x);