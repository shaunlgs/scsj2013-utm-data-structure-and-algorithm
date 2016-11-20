// Program 6.6
int Carian(int search_key, month arrayA[], int array_size)
{
    int p;
    int index = -1;
    for(p=0; p<array_size; p++)
    {
        if(arrayA[p].key == search_key)
        {
            index = p; // if record is found, assign current array index
            break;
        }
        else if (arrayA[p].key < search_key)
        {
            break; // else, no need to continue search on the remaining records
        }
    } // end for
    return index;
} // end function
