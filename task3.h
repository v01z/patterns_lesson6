#include <vector>

class Image{
public:
    virtual void openFile(const std::string &filename) final{
        std::cout << "Open file " << filename << std::endl;
    }

    virtual void readImageFile() = 0;
    virtual void draw() = 0;
    virtual void final() = 0;

    //Template method
    virtual void doImage(const std::string& filename) final{
        openFile(filename);
        readImageFile();
        draw();
        final();
    }
};

struct Pixel{
    int x;
    int y;
    std::string color;

    void draw(){
        std::cout << "("<< x << ", " << y << ", " << color << ") ";
    }
};

class BitmapImage: public Image{        // Растровое изображение
private:
    std::vector<Pixel*> pixels;     // это пиксели, которые хранятся в файле
    std::vector<Pixel> buffer;      // это пиксели, которые мы читаем для отображение на экране
public:
    void readBitmapFile() {
        for (const auto pixel: pixels) {
            buffer.push_back(*pixel);      // Имитируем чтение пикселей из файла в буфер
        }
    };

    void readImageFile() override{
        readBitmapFile();
    }

    void draw() override{
         for (auto pixel: buffer) {
            pixel.draw(); // Рисуем каждый пиксель из буфера
        }
    }

    void final() override{
        std::cout << "Drawing bitmap image complete" << std::endl;
    }
};

struct Figure{
    int x;
    int y;
    std::string figure;

    void draw(){
        std::cout << "("<< x << ", " << y << ", " << figure << ") ";
    }
};

class VectorImage: public Image{        // Векторное изображение
private:
    std::vector<Figure*> figures;     // это описание фигур, которые хранятся в файле
    std::vector<Figure> buffer;       // это описание фигур, которые мы читаем для отображение на экране
public:
    void readVectorFile() {
        for (const auto figure: figures) {
            buffer.push_back(*figure);        // Имитируем чтение фигур из файла в буфер
        }
    };

    void readImageFile() override{
        readVectorFile();
    }

    void draw() override{
        for (auto figure: buffer) {
            figure.draw(); // Рисуем каждую фигуру из буфера
        }
    }

    void final() override{
        std::cout << "Drawing vector image complete" << std::endl;
    }
};
