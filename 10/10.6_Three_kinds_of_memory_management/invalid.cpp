/*
 * this function yields an invalid pointer.
 * it is intended as a negative example, don't do this
 */

int *invalid_pointer()
{
        int x;
        return &x; // instant disaster
}
