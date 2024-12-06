


class Image
{
public:

	Image();
	Image(int height, int width);
	Image(int height, int width, Pixel pixel);

	Image operator+(const Image& rhs) const;

	bool operator==(const Image& image) const;
	bool operator!=(const Image& image) const;

    Image operator+(const Image& image)const;
	Image operator+=(const Image& image);

	const Image& operator|(const Image& image)const;
    Image& operator|=(const Image& image);

	const Image& operator&(const Image& image)const;
    Image& operator&=(const Image& image);

	const Image& operator*(const Image&);
	const Image& operator~()const;

	Pixel** operator()(unsigned int x, unsigned int y);
	const Pixel** operator()(unsigned int x, unsigned int y);

	const int getWidth();
	const int getHeight();
};