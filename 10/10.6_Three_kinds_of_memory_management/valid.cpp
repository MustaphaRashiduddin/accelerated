// this function is completely legitimate

int *pointer_to_static()
{
        static int x;
        return &x;
}
