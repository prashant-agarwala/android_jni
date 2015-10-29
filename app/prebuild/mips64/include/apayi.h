#ifndef __APAYI_H__
#define __APAYI_H__

#include <vector>
#include "payment.h"

namespace apayi
{
	extern string CLIENT_ID;
	extern string SECRET_KEY;

	payment get_payment_by_id(const string& id);
	std::vector<payment> get_payments();
	payment get_payment_with_refunds_by_payment_id(const string& id);
	refund get_refund_by_payment_id_and_refund_id(const string& txn_id, const string& refund_id);
	std::vector<refund> get_refunds_for_payment_id(const string& txn_id);
	std::vector<refund> get_refunds_for_payment_id(const string& txn_id, unsigned int count);
	void capture_by_payment_id(const string& txn_id, const string& amount, const string& currency);
	void make_refund(const string& txn_id, const string& amount, const string& currency, const string& reason);
}
#endif
