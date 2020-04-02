class OurString
{
    public:
        // Student A
        OurString(OurString &string);
        char* c_str();
        size_t size();
        void clear();
        OurString operator=(char c);
        OurString operator+(const string&, const char* s);

        // Student B
        OurString(char &string);
        size_t length();
        size_t max_size();
        void resize(size_t n, char c);
        OurString operator=(const string&);
        OurString operator+(const string&, char c);

    protected:
        char* string_;
};