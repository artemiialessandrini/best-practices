// На марсе есть станция, которая посылает на спутник ретранслятор (предположительно на лунной орбите) видеопоток
// c fps 30. К спутнику ретранслятору подключаются клиенты с земли для получения видео потока.
// Максимум может подключиться 5 клиентов. Память спутника ретранслятора ограничена и может хранить не больше 30 кадров (Frame)
// Данные посылаются клиентам через вызов Result SendFrame(const std::string &addr, Frame &f), который является
// блокирующем.
// Задача: Закончить MarsCamStreamer

// 5 клиентов


#include <string>
class Frame {
public:
    Frame(const std::string &data, uint64_t ts);

    ~Frame() = default;

    uint64_t GetTimeStamp() const {
        return timestamp;
    }

    const std::string &GetData() const {
        return data;
    }

private:
    std::string data; // base64
    uint64_t timestamp; // unix time
};

// external API available
enum Result {
    OK,
    ERR //
};

// This is a blocking function
//
Result SendFrame(const std::string &addr, Frame &f);

// Singleton instance
class MarsCamStreamer {
public:
    MarsCamStreamer() = default;
    MarsCamStreamer(size_t client_num)
            : client_num_(client_num) {}

    ~MarsCamStreamer() = default;

    /*
     * connect user to the stream
     */
    void OnEarthClientConnected(const std::string &addr) {

        // TODO your code should be here
    }
    void OnEarthClientDisconnected(const std::string &addr) {
        // TODO your code should be here
    }
    /*
     * Got the frame from Mars
     *
     **/
    void OnFrameFromMars(Frame &f) {
        // TODO your code should be here
    }
    /*
     *
     */
private:
    size_t client_num_ = 0;

// TODO: Add other methods you would like to use for your implementation
};

int main() {
    return 0;
}