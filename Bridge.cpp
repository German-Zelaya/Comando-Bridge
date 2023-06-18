#include <iostream>

// Implementación del puente
class ImplementacionControl {
public:
    virtual void encender() = 0;
    virtual void apagar() = 0;
    virtual void aumentarVolumen() = 0;
    virtual void disminuirVolumen() = 0;
    virtual void cambiarCanal(int canal) = 0;
};

// Implementación concreta para el control de televisión
class ImplementacionControlTV : public ImplementacionControl {
public:
    void encender() override {
        std::cout << "Encendiendo el televisor..." << std::endl;
    }

    void apagar() override {
        std::cout << "Apagando el televisor..." << std::endl;
    }

    void aumentarVolumen() override {
        std::cout << "Aumentando el volumen del televisor..." << std::endl;
    }

    void disminuirVolumen() override {
        std::cout << "Disminuyendo el volumen del televisor..." << std::endl;
    }

    void cambiarCanal(int canal) override {
        std::cout << "Cambiando el canal del televisor a " << canal << std::endl;
    }
};

// Implementación concreta para el control de radio
class ImplementacionControlRadio : public ImplementacionControl {
public:
    void encender() override {
        std::cout << "Encendiendo la radio..." << std::endl;
    }

    void apagar() override {
        std::cout << "Apagando la radio..." << std::endl;
    }

    void aumentarVolumen() override {
        std::cout << "Aumentando el volumen de la radio..." << std::endl;
    }

    void disminuirVolumen() override {
        std::cout << "Disminuyendo el volumen de la radio..." << std::endl;
    }

    void cambiarCanal(int canal) override {
        std::cout << "Cambiando el canal de la radio a " << canal << std::endl;
    }
};

// Implementación concreta para el control de TV Box
class ImplementacionControlTVBox : public ImplementacionControl {
public:
    void encender() override {
        std::cout << "Encendiendo la TV Box..." << std::endl;
    }

    void apagar() override {
        std::cout << "Apagando la TV Box..." << std::endl;
    }

    void aumentarVolumen() override {
        std::cout << "Aumentando el volumen de la TV Box..." << std::endl;
    }

    void disminuirVolumen() override {
        std::cout << "Disminuyendo el volumen de la TV Box..." << std::endl;
    }

    void cambiarCanal(int canal) override {
        std::cout << "Cambiando el canal de la TV Box a " << canal << std::endl;
    }
};

// Abstracción del control remoto
class ControlRemoto {
protected:
    ImplementacionControl* implementacion;

public:
    ControlRemoto(ImplementacionControl* implementacion) : implementacion(implementacion) {}

    void encender() {
        implementacion->encender();
    }

    void apagar() {
        implementacion->apagar();
    }

    void aumentarVolumen() {
        implementacion->aumentarVolumen();
    }

    void disminuirVolumen() {
        implementacion->disminuirVolumen();
    }

    void cambiarCanal(int canal) {
        implementacion->cambiarCanal(canal);
    }
};

// Cliente
int main() {
    ImplementacionControlTV tvImplementacion;
    ImplementacionControlRadio radioImplementacion;
    ImplementacionControlTVBox tvBoxImplementacion;

    ControlRemoto tvControlRemoto(&tvImplementacion);
    ControlRemoto radioControlRemoto(&radioImplementacion);
    ControlRemoto tvBoxControlRemoto(&tvBoxImplementacion);

    // Control de televisión
    tvControlRemoto.encender();
    tvControlRemoto.aumentarVolumen();
    tvControlRemoto.cambiarCanal(5);
    tvControlRemoto.apagar();

    // Control de radio
    radioControlRemoto.encender();
    radioControlRemoto.disminuirVolumen();
    radioControlRemoto.cambiarCanal(98);
    radioControlRemoto.apagar();

    // Control de TV Box
    tvBoxControlRemoto.encender();
    tvBoxControlRemoto.aumentarVolumen();
    tvBoxControlRemoto.cambiarCanal(123);
    tvBoxControlRemoto.apagar();

    return 0;
}