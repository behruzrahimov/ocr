#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

int main() {
    char *outText;
    auto *api = new tesseract::TessBaseAPI();

    if (api->Init(nullptr, "eng")) {
        fprintf(stderr, "Could not initialize Tesseract.\n");
        exit(1);
    }

    Pix *image = pixRead("./image.png");
    api->SetImage(image);
    outText = api->GetUTF8Text();

    printf("Recognized text:\n%s", outText);

    // Cleanup
    api->End();
    delete [] outText;
    pixDestroy(&image);
    return 0;
}
