class OurString
{
    public:
        OurString();
        ~OurString();

        // Student A
        OurString(OurString &string);
        const char* c_str() const;
        size_t size() const;
        void clear();
        OurString& operator=(char c);
        OurString operator+(const char* s);

        // Student B
        OurString(const char* s);
        size_t length() const;
        size_t max_size() const;
        void resize(std::size_t n, char c);
        OurString& operator=(const OurString &string);
        OurString operator+(char c);

    protected:
        char* string_;
        size_t size_(const char* s) const;
        char* copy_(char* dest, const char* src);
};