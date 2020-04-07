class OurString
{
    public:
        OurString();
        // Student A
        OurString(OurString &string);
        char* c_str();
        size_t size();
        void clear();
        OurString operator=(char c);
        OurString operator+(const char* s);

        // Student B
        OurString(const char* s);
        size_t length();
        size_t max_size();
        void resize(size_t n, char c);
        OurString operator=(const OurString &string);
        OurString operator+(char c);
        
    protected:
        char string_[101];
        FRIEND_TEST(GTestTests, ResizeTest); // permet d'effectuer des test sur la chaine de caractère string_ qui est protégée
        FRIEND_TEST(GTestTests, Ope_PLUS_SingCHAR);
};