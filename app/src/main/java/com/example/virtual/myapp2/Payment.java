package com.example.virtual.myapp2;

import java.util.ArrayList;

/**
 * Created by administrator on 30/10/15.
 */
public class Payment {
    public Payment() {
    }

    private String amount;
    private int created_at;
    private String currency;
    private String id;
    private ArrayList<Refund> refunds ;
    //private Refund refund ;

    public String getAmount() {
        return amount;
    }

    public int getCreated_at() {
        return created_at;
    }

    public String getCurrency() {
        return currency;
    }

    public String getId() {
        return id;
    }

    public ArrayList<Refund> getRefunds() {
        return refunds;
    }

   /* public Refund getRefund() {
        return refund;
    }*/
}
