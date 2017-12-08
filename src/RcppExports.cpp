// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// rcpp_cppDataFrameInterface
SEXP rcpp_cppDataFrameInterface(Rcpp::List x, Rcpp::NumericVector y, Rcpp::NumericVector catCols, int numRows, int numColumns);
RcppExport SEXP forestry_rcpp_cppDataFrameInterface(SEXP xSEXP, SEXP ySEXP, SEXP catColsSEXP, SEXP numRowsSEXP, SEXP numColumnsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type x(xSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type catCols(catColsSEXP);
    Rcpp::traits::input_parameter< int >::type numRows(numRowsSEXP);
    Rcpp::traits::input_parameter< int >::type numColumns(numColumnsSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_cppDataFrameInterface(x, y, catCols, numRows, numColumns));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_cppBuildInterface
SEXP rcpp_cppBuildInterface(Rcpp::List x, Rcpp::NumericVector y, Rcpp::NumericVector catCols, int numRows, int numColumns, int ntree, bool replace, int sampsize, int mtry, float splitratio, int nodesizeSpl, int nodesizeAvg, int seed, int nthread, bool verbose, bool middleSplit, bool existing_dataframe_flag, SEXP existing_dataframe);
RcppExport SEXP forestry_rcpp_cppBuildInterface(SEXP xSEXP, SEXP ySEXP, SEXP catColsSEXP, SEXP numRowsSEXP, SEXP numColumnsSEXP, SEXP ntreeSEXP, SEXP replaceSEXP, SEXP sampsizeSEXP, SEXP mtrySEXP, SEXP splitratioSEXP, SEXP nodesizeSplSEXP, SEXP nodesizeAvgSEXP, SEXP seedSEXP, SEXP nthreadSEXP, SEXP verboseSEXP, SEXP middleSplitSEXP, SEXP existing_dataframe_flagSEXP, SEXP existing_dataframeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type x(xSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type catCols(catColsSEXP);
    Rcpp::traits::input_parameter< int >::type numRows(numRowsSEXP);
    Rcpp::traits::input_parameter< int >::type numColumns(numColumnsSEXP);
    Rcpp::traits::input_parameter< int >::type ntree(ntreeSEXP);
    Rcpp::traits::input_parameter< bool >::type replace(replaceSEXP);
    Rcpp::traits::input_parameter< int >::type sampsize(sampsizeSEXP);
    Rcpp::traits::input_parameter< int >::type mtry(mtrySEXP);
    Rcpp::traits::input_parameter< float >::type splitratio(splitratioSEXP);
    Rcpp::traits::input_parameter< int >::type nodesizeSpl(nodesizeSplSEXP);
    Rcpp::traits::input_parameter< int >::type nodesizeAvg(nodesizeAvgSEXP);
    Rcpp::traits::input_parameter< int >::type seed(seedSEXP);
    Rcpp::traits::input_parameter< int >::type nthread(nthreadSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    Rcpp::traits::input_parameter< bool >::type middleSplit(middleSplitSEXP);
    Rcpp::traits::input_parameter< bool >::type existing_dataframe_flag(existing_dataframe_flagSEXP);
    Rcpp::traits::input_parameter< SEXP >::type existing_dataframe(existing_dataframeSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_cppBuildInterface(x, y, catCols, numRows, numColumns, ntree, replace, sampsize, mtry, splitratio, nodesizeSpl, nodesizeAvg, seed, nthread, verbose, middleSplit, existing_dataframe_flag, existing_dataframe));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_cppPredictInterface
Rcpp::NumericVector rcpp_cppPredictInterface(SEXP forest, Rcpp::List x);
RcppExport SEXP forestry_rcpp_cppPredictInterface(SEXP forestSEXP, SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type forest(forestSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_cppPredictInterface(forest, x));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_OBBPredictInterface
float rcpp_OBBPredictInterface(SEXP forest);
RcppExport SEXP forestry_rcpp_OBBPredictInterface(SEXP forestSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type forest(forestSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_OBBPredictInterface(forest));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_getObservationSizeInterface
float rcpp_getObservationSizeInterface(SEXP df);
RcppExport SEXP forestry_rcpp_getObservationSizeInterface(SEXP dfSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type df(dfSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_getObservationSizeInterface(df));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_AddTreeInterface
void rcpp_AddTreeInterface(SEXP forest, int ntree);
RcppExport SEXP forestry_rcpp_AddTreeInterface(SEXP forestSEXP, SEXP ntreeSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type forest(forestSEXP);
    Rcpp::traits::input_parameter< int >::type ntree(ntreeSEXP);
    rcpp_AddTreeInterface(forest, ntree);
    return R_NilValue;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"forestry_rcpp_cppDataFrameInterface", (DL_FUNC) &forestry_rcpp_cppDataFrameInterface, 5},
    {"forestry_rcpp_cppBuildInterface", (DL_FUNC) &forestry_rcpp_cppBuildInterface, 18},
    {"forestry_rcpp_cppPredictInterface", (DL_FUNC) &forestry_rcpp_cppPredictInterface, 2},
    {"forestry_rcpp_OBBPredictInterface", (DL_FUNC) &forestry_rcpp_OBBPredictInterface, 1},
    {"forestry_rcpp_getObservationSizeInterface", (DL_FUNC) &forestry_rcpp_getObservationSizeInterface, 1},
    {"forestry_rcpp_AddTreeInterface", (DL_FUNC) &forestry_rcpp_AddTreeInterface, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_forestry(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
