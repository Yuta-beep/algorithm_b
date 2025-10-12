typedef int Key;
typedef struct {Key key; char information[10];} Data;
#define key(A) (A.key)

#define less(A,B) (A<B)
#define exch(A,B){Data t=A;A=B;}
#define compexch(A,B) if(less(B,A)) exch(A,B)
#define eq(A,B)(A==B)

extern Data NULLdata;

Key DATArand(void);
int DATAscan(Key *);
void DATAshow(Data);