    int n;
    cin >> n;
    vector<int> nums(n);
        cin >> nums[i];
    }
    for (int i = 1; i < n; i++) {

    int right = 1;
    for (int i = n - 2; i >= 0; i--) {
        output[i] *= right * nums[i + 1];
    }
        cout << output[i] << " ";
    }
    cout << endl;

}