list<int> metafora(list<int>& pos)
{
    list<int> pos_f;
    int f,a,i;
    list<int>::iterator it=pos.begin();
    while(it!=pos.end())
    {
        f=((*it)-1)/75;
        a=(*it)-f*75;
        pos_f.push_back(f+1);
        pos_f.push_back(a);
        it++;
    }

    return pos_f;
}
