struct s {
    int value;
};

program MOD_STRUCT {
    version MOD_STRUCT_V1 {
        s MOD_S(s) = 1;
    } = 1;
} = 0x2fffffff;
