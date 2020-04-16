class OurString
{
    public:
        OurString();
        
        // Student A
        OurString(OurString &string);
        const char* c_str() const;
        std::size_t size() const;
        void clear();
        OurString& operator=(char c);
        OurString operator+(const char* s);

        // Student B
        OurString(const char* s);
        std::size_t length() const;
        std::size_t max_size() const;
        void resize(std::size_t n, char c);
        OurString& operator=(const OurString &string);
        OurString operator+(char c);

    protected:
        char string_[100];
};