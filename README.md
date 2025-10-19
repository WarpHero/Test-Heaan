# Dataset Overview

This dataset originates from **COIL20.mat** and contains image feature matrices for the COIL-20 object recognition dataset.

## Dataset Structure

The `.mat` file includes four main keys:

| Key | Shape | Description |
|-----|--------|-------------|
| `X` | (1024, 280) | Test set features |
| `Xt` | (1024, 1160) | Training set features |
| `Y` | (1, 280) | Test set labels |
| `Yt` | (1, 1160) | Training set labels |

## Data Conversion

- `X_test` → **Transpose of X**, resulting in shape **(280, 1024)**  
- `X_train` → **Transpose of Xt**, resulting in shape **(1160, 1024)**

## Small Feature Subset

To create subsets with reduced dimensionality (using 50 selected features):

- **X_test_small50** → Extract 50 features from `X`
- **X_train_small50** → Extract 50 features from `Xt`

These reduced versions are useful for dimensionality reduction experiments and quick model testing.

## Summary

| Variable | Source | Operation | Shape |
|-----------|---------|------------|--------|
| X_test | X | Transpose | (280, 1024) |
| X_train | Xt | Transpose | (1160, 1024) |
| X_test_small50 | X | 50-feature subset | (50, 280) before transpose |
| X_train_small50 | Xt | 50-feature subset | (50, 1160) before transpose |



