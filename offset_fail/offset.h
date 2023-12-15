struct Line {
    int num_segments;
    struct Rail segments[9]; // max size will always be 9 in our example route
};

int calculate_departure_offset(struct Line *ICL_train_line, struct Line *HST_train_line);

