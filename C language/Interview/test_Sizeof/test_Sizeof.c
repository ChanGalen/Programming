/******************************************
*date:*  2016/5/22
*description:* test the founction of sizeof() 
******************************************/

int main(int argc, char const *argv[])
{
	/* code */
	char str[] = "xunlei";
	char *p = str;
	int n = 10;
	printf("sizeof(str) = %d,  sizeof(p) = %d,  sizeof(n) = %d\n", sizeof(str), sizeof(p), sizeof(n));

	return 0;
}