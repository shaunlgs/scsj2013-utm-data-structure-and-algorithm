// Program 6.7
int Binary_Search(int search_key, month arrayA[], int array_size)
{
    bool found = false;
    int MIDDLE, LEFT = 0, RIGHT = array_size - 1;
    int i = -1;
    while((LEFT <=RIGHT) && (!foubd))
    {
        MIDDLE = (LEFT + RIGHT) / 2;
        if(arrayA[MIDDLE].key == search_key)
        {
            i = MIDDLE;
            found = true;
        }
        else if (arrayA[MIDDLE].key < search_key)
            RIGHT = MIDDLE - 1; // search is focused on the left side of list
        else
            LEFT = MIDDLE + 1; // search is focused on the right side of the list
    } // end while
    return i;
} // end function
