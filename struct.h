typedef struct body body;
typedef struct head head;
typedef struct food food;

struct food {
   int x,y;
};

struct body {
   int x,y;
};

struct head {
	int dir;
	int x,y;
};
