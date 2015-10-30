package com.example.virtual.myapp2;

/**
 * Created by administrator on 30/10/15.
 */
public class Refund {
    private String amount;
    private int created_at;
    private String currency;
    private String entity;
    private String notes;
    private String payment_id;
    private String id;

    public Refund() {
    }

    public String getAmount() {
        return amount;
    }

    public int getCreated_at() {
        return created_at;
    }

    public String getCurrency() {
        return currency;
    }

    public String getEntity() {
        return entity;
    }

    public String getNotes() {
        return notes;
    }

    public String getPayment_id() {
        return payment_id;
    }

    public String getId() {
        return id;
    }
}
