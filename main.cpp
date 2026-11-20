#include "Libraries/bitmap.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  string inputFilename;
  string outputFilename;
  Bitmap bitmap;
  PixelMatrix pixels;

  cout << "Input bitmap filename: ";
  cin >> inputFilename;
  cout << "Output bitmap filename: ";
  cin >> outputFilename;

  bitmap.open(inputFilename);

  if (!bitmap.isImage()) {
    cout << "Could not open a valid bitmap image.\n";
    return 1;
  }

  pixels = bitmap.toPixelMatrix();
  for (vector<Pixel> &row : pixels) {
    for (Pixel &pixel : row) {
      pixel.red /= 2;
    }
  }

  bitmap.fromPixelMatrix(pixels);
  bitmap.save(outputFilename);

  return 0;
}
