#include <X11/Xlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    Display *display = XOpenDisplay(0);
    if (!display) {
        perror("failed to open X11 display");
        return -1;
    }
    Window window = XCreateSimpleWindow(display, XDefaultRootWindow(display), 0, 0, 1, 1, 0, 0, 0);

    Atom property = XInternAtom(display, "search it", 0);
    XConvertSelection(display, XInternAtom(display, "PRIMARY", 0), XInternAtom(display, "STRING", 0), property, window, CurrentTime);

    XEvent event;
    XNextEvent(display, &event);
    if (event.type != SelectionNotify || !event.xselection.property) {
        fprintf(stderr, "there is no selection notification!");
        return -1;
    }

    unsigned long buf;
    unsigned char *selected_data;
    XGetWindowProperty(display, window, property, 0, -1, 0, PropertyNewValue, &buf, (int *)&buf, &buf, &buf, &selected_data);

    char url[BUFSIZ];
    sprintf(url, "https://www.google.com/search?q=%s", selected_data);

    char *browsers[] = {
        "firefox","google-chrome","brave","opera","vivaldi",
        "midori","falkon","waterfox","palemoon","seamonkey",
        "epiphany","links","lynx","w3m","chromium",NULL
    };
    for (char **browser = browsers; *browser != NULL; browser++)
        execlp(*browser, *browser, url, NULL);

    return 0;
}
