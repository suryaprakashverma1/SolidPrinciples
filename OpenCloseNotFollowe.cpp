class FiringSystem {
public:
    string fire(string type) {
        if (type == "Infrared") {
            return "Fired using Infrared";
        }
        else if (type == "Laser") {
            return "Fired using Laser";
        }
        else if (type == "GPS") {
            return "Fired using GPS";
        }
        return "Unknown firing type";
    }
};
