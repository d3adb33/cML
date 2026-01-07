#include <stdlib.h>
#include <stdio.h>

struct datapoint {
    double x, y;
};

struct model {
    double w, b;
};

double predict(double x, struct model m) {
    return (m.w * x + m.b);
};

double squared_error(double y, double y_pred) {
    return (y_pred - y) * (y_pred - y);
};

double mse(struct model m, struct datapoint data[], int n) {

    double ms_error = 0.0;
    double y_pred = 0.0;
    double error = 0.0;

    for (int i = 0; i < n; i++) {
        y_pred = predict(data[i].x, m);
        error = squared_error(data[i].y, y_pred);
        ms_error = ms_error + error;
    }
    double mse_output = ms_error / n;
    return mse_output;
}

struct model_train_step(struct model m, struct datapoint data[], int n, double learning_rate) {
        
}

int main() {    

    //init training data
    struct datapoint train_data[5];
    for (int i = 0; i < 5; i++) {
        train_data[i].x = i;
        train_data[i].y = i * 2;
    }

    //init weights and bias
    struct model model;
    model.w = (double)rand() / (RAND_MAX + 1.0);
    model.b = (double)rand() / (RAND_MAX + 1.0);

    //implementation of predection -> y=w*x+b
    for (int i = 0; i < 5; i++) {

        double pred = predict(train_data[i].x, model);        
        printf("x: %.2f, \n", train_data[i].x);
        printf("y: %.2f, \n", train_data[i].y);
        printf("Prediction: %.2f, \n", pred);
    }

    double mean_squared_error = mse(model, train_data, 5);
    printf("MSE: %.2f", mean_squared_error);

    return 0;
}
