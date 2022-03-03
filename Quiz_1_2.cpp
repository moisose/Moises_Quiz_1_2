/* Quiz 1 y 2 
Analisis de Algoritmos
Estudiante: Moises Solano Espinoza
Carne: 2021144322
Grupo: 01 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Enumeracion de tipos de media 
enum mediaType {VIDEO, AUDIO, FOTO};

//funcion para imprimir el tipo de dato
string mediaName(int ptipo){
    if(ptipo == 0){
        return "Video";
    }
    if(ptipo == 1){
        return "Audio";
    }
    return "Foto";
}

// Clase para los datos media de la clase Digital
class Media {
    private:
        mediaType tipo;
        string dato;
        string artista;
        string fecha;
    public:
        Media(){
        }

        Media(mediaType ptipo, string pdato, string partista, string pfecha) {
            tipo = ptipo;
            dato = pdato;
            artista = partista;
            fecha = pfecha;
        }

        void setTipo(mediaType ptipo){
            tipo = ptipo;
        }

        mediaType getTipo(){
            return tipo;
        }

        void setDato(string pdato){
            dato = pdato;
        }

        string getDato(){
            return dato;
        }

        void setArtista(string partista){
            artista = partista;
        }

        string getArtista(){
            return artista;
        }

        void setFecha(string pfecha){
            fecha = pfecha;
        }

        string getFecha(){
            return fecha;
        }

        void toString (){
            cout << "{Tipo: " << mediaName(tipo) << ", Dato: " << dato <<
            ", Artista: " << artista << ", Fecha: " << fecha << "}" << endl;
        }
};

// Clase principal de noticia de la que heredan
// las clases hijas
class Noticia {
    protected:
        string titulo;
        string fecha;
        string reportero;
    public:
        Noticia(){
        }

        Noticia (string tit, string fech, string rep){
            titulo = tit;
            fecha = fech;
            reportero = rep;
        }

        void setTitulo (string tit){
            titulo = tit;
        }

        string getTitulo (){
            return titulo;
        }

        void setFecha (string fech){
            fecha = fech;
        }

        string getFecha (){
            return fecha;
        }

        void setReportero (string rep){
            reportero = rep;
        }

        string getReportero (){
            return reportero;
        } 

        // funcion que sera implementada en las hijas
        virtual void getInfo() = 0;
};

// Clase de NoticiaPaper que hereda de Noticia
class NoticiaPaper: public Noticia {
    private:
        string rutaFoto;
    public:
        NoticiaPaper(string ruta){
            rutaFoto = ruta;
        }

        NoticiaPaper(string tit, string fech, string rep, string ruta) {
            titulo = tit;
            fecha = fech;
            reportero = rep;
            rutaFoto = ruta;
        }
        
        void setRutaFoto(string ruta){
            rutaFoto = ruta;
        }

        string getRutaFoto(){
            return rutaFoto;
        }

        // funcion implementada
        void getInfo() {
            cout << "---------------------" << endl;
            cout << "NOTICIA DE TIPO PAPER" << endl;
            cout << "---------------------" << endl;
            cout << "{\n-> Titulo: " << titulo << "\n-> Fecha: " << fecha <<
            "\n-> Reportero: " << reportero << "\n-> Ruta foto: " << rutaFoto << "\n}" << endl;
        }
};

// Clase de NoticiaDigital que hereda de Noticia
class NoticiaDigital: public Noticia{
    private:
        vector<Media> media;
    public:
        // se quiere instanciar con solo un objeto media, luego se pueden agregar mas
        NoticiaDigital(string tit, string fech, string rep, Media med) {
            titulo = tit;
            fecha = fech;
            reportero = rep;
            media.push_back(med);
        }
        // se quiere instanciar con un vector ya hecho con medias adentro
        NoticiaDigital(string tit, string fech, string rep, vector<Media> med) {
            titulo = tit;
            fecha = fech;
            reportero = rep;
            media = med;
        }

        // se quiere instanciar sin media, luego se puede agregar
        NoticiaDigital(string tit, string fech, string rep) {
            titulo = tit;
            fecha = fech;
            reportero = rep;
        }
        
        // agregar un objeto media al vector de media
        void addMedia(Media med){
            media.push_back(med);
        }

        vector<Media> getMedia(){
            return media;
        }

        // funcion implementada
        void getInfo() {
            cout << "----------------------" << endl;
            cout << "NOTICIA DE TIPO DIGITAL" << endl;
            cout << "----------------------" << endl;
            cout << "{\n-> Titulo: " << titulo << "\n-> Fecha: " << fecha <<
            "\n-> Reportero: " << reportero << "\n-> Archivos media:" << endl;

            if (media.size() == 0){
                cout<< "AUN NO HAY MEDIA EN ESTA NOTICIA" << endl;
            }

            for(int i = 0; i < media.size(); i++){
                cout<< "\t- Tipo de media: {" << mediaName(media[i].getTipo()) 
                << "}, Dato: {" << media[i].getDato() << "}, Artista: {" << 
                media[i].getArtista() << "}, Fecha: {" << media[i].getFecha() << "}" <<  endl;
            }
            cout << "}" << endl;
        }
};

// Clase de NoticiaRadio que hereda de Noticia
class NoticiaRadio: public Noticia{
    private:
        string audio;
    public:
        NoticiaRadio(string url){
            audio = url;
        }

        NoticiaRadio(string tit, string fech, string rep, string url) {
            titulo = tit;
            fecha = fech;
            reportero = rep;
            audio = url;
        }

        void setAudio(string url){
            audio = url;
        }

        string getAudio(){
            return audio;
        }

        // funcion implementada
        void getInfo() {
            cout << "---------------------" << endl;
            cout << "NOTICIA DE TIPO RADIO" << endl;
            cout << "---------------------" << endl;
            cout << "{\n-> Titulo: " << titulo << "\n-> Fecha: " << fecha <<
            "\n-> Reportero: " << reportero << "\n-> URL audio: " << audio << "\n}" << endl;
        }
};

int main(){
    // objeto tipo paper
    NoticiaPaper noticia1("Delicias de Mamedyarov", "02/03/2022", "Leontxo Garcia", "C:/Users/Moises/Pictures/Saved Pictures/88561.jpeg");

    // media que se utiliza en noticia digital
    Media archivo(FOTO, "C:/Users/Moises/Pictures/hola.jpg", "Moises", "2022");
    Media archivo2(VIDEO, "https://youtu.be/F4neLJQC1_E", "Moises", "2022");
    Media archivo3(AUDIO, "https://theproaudiofiles.com/chorus-plugins/", "Moises", "2020");

    //NoticiaDigital noticia2("Costa Rica se incorpora cada vez mas en estrategia BIM", "19/02/2022", "Jocelyn Espinoza", archivo);
    NoticiaDigital noticia2("Costa Rica se incorpora cada vez mas en estrategia BIM", "19/02/2022", "Jocelyn Espinoza");
    noticia2.addMedia(archivo); // se agrega la media a la noticia
    noticia2.addMedia(archivo2);
    noticia2.addMedia(archivo3);

    // objeto tipo NoticiaRadio
    NoticiaRadio noticia3("Elaborado escenario de Coldplay llego al pais en 31 contenedores.", "01/03/2022", "Maria Jesus Rodriguez", "https://theproaudiofiles.com/chorus-plugins/");

    // vector con noticias
    vector<Noticia*> v {&noticia1, &noticia2, &noticia3};

    // Prints de los getInfo() de cada clase
    for(int i=0; i < v.size(); i++){
        v[i]->getInfo();
    }

    return 0;

}